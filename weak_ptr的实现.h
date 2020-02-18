#pragma once
//模板化接受任意类型
//构造方法 赋值一个指针
//析构方法释放指针
//不标准赋值构造（转移内部控制权）
//不标准复制复制
//reset 释放之前的，获得新指针
//release()释放控制权返回指针
//operator*()模拟指针访问方法
//operator->() 模拟指针箭头式访问方法
//get() 获得指针指向的指针
template<class T>
class X_autoptr{
	T*obj = nullptr;
public:
	X_autoptr(T* ptr) :obj(ptr){

	}
	X_autoptr() = default;
	~X_autoptr(){
		delete obj;
	}
	X_autoptr(X_autoptr<T>& ptr){
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	X_autoptr& operator=(X_autoptr<T>&ptr){
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T *newPtr){
		delete obj;
		obj = newPtr;
	}
	T* release(){
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	T& operator*(){
		return *obj;
	}
	T* operator->(){
		return obj;
	}
	T* get(){
		return obj;
	}
};

namespace Xu{
	template<class T>
	class Ref{
		T* obj = nullptr;
		int r_cout = 0;
		int w_cout = 0;
	public:
		Ref() = default;
		Ref(T* target) :obj(target), r_cout(1), w_cout(1){

		}
		inline void reduce(){
			r_cout--;//因为这个引用对象建立时就置为1
			if (r_cout == 0){
				delete obj;//释放指向对象
				obj = nullptr;
				//当w也为0才释放引用
				if (w_cout == 0){
					delete this;//释放当前引用对象
				}
			}
		}
		inline void w_reduce(){
			w_cout--;//因为这个引用对象建立时就置为1
			if (w_cout == 0 && r_cout == 0){//强弱都没有才释放
				delete this;//释放当前引用对象
			}
		}
		inline void increase(){
			r_cout++;
		}
		inline void w_increase(){
			w_cout++;
		}
		T* get(){
			return obj;
		}
		int getCout(){
			return r_cout;
		}
	};
	//提前声明 否则会报Xu不是模板的错误
	template<class T> class Xweak_ptr;
	template<class T>
	class Xshared_ptr{
		Ref* ref = nullptr;
		friend class Xweak_ptr<T>;
	public:
		Xshared_ptr() = default;
		Xshared_ptr(Ref* newRef){
			ref = newRef;
			if (ref){
				ref->increase();
			}
		}
		Xshared_ptr(T* newP){
			ref = new Ref<T>(newP);
		}
		~Xshared_ptr(){
			if (ref){
				ref->reduce();
			}
		}
		Xshared_ptr(const Xshared_ptr<T> &other){//other为被拷对象
			ref = other->ref;
			if (ref){
				ref->increase();
			}
		}
		Xshared_ptr(const Xshared_ptr<T> &&other){//移动构造直接可以交换函数
			swap(ref, other->ref);
		}
		Xshared_ptr& operator=(const Xshared_ptr<T>&other){//1.返回值引用才能操作 
			if (ref){
				ref->reduce();//指针被赋值后引用内个数减一或析构对象
			}
			ref = other->ref;
			if (ref){
				ref->increase();
			}
		}
		Xshared_ptr& operator=(const Xshared_ptr<T>&&other){//把传进来的搞空喽
			if (ref){
				ref->reduce();
			}
			ref = other->ref;
			other.ref = nullptr;//指针没丢传给另一个对象
			return *this;
		}
		void swap(Xshared_ptr<T> &other){
			swap(ref, other->ref);
		}
		void reset(T* target = nullptr){
			if (ref){
				ref->reduce();
			}
			if (target != nullptr){
				ref = new Ref<T>(target);
			}
			else{
				ref = nullptr;
			}

		}
		T& operator*(){
			if (ref){
				return *ref->get();
			}
			else{
				return *(T*)nullptr;
			}
		}
		T* operator->(){
			if (ref){
				return ref->get();
			}
			else{
				return (T*)nullptr;
			}
		}
		T* get(){
			if (ref){
				return ref->get();
			}
			else{
				return (T*)nullptr;
			}
		}
		int use_count(){
			if (ref){
				return ref->getCout();
			}
			else{
				return 0;
			}
		}
		bool unique(){
			if (ref){
				return ref->getCout() == 1;
			}
			else{
				return false;
			}

		}
	};


	//Xweak_ptr的实现
	template<class T>
	class Xweak_ptr{
		Ref<T>* ref = nullptr;
	public:
		Xweak_ptr() = default;
		Xweak_ptr(const Xshared_ptr<T>& other) :ref(other.ref){
			if (ref){
				ref->w_reduce;
			}
		}
		Xweak_ptr(const Xweak_ptr&other) :ref(other.ref){
			if (ref){
				ref->w_increase();
			}
		}
		Xweak_ptr(Xweak_ptr&& other){
			swap(ref, other.ref);
		}
		void operator=(const Xweak_ptr& other){
			if (ref){
				ref->w_reduce();
			}
			ref = other.ref;
			if (ref){
				ref->w_increase();
			}
		}
		int use_cout(){
			if (ref){
				return ref->getCout();
			}
			else{
				return 0
			}
		}
		bool expired(){
			if (ref){
				return ref->getCout() > 0;
			}
			else{
				return false;
			}
		}
		Xshared_ptr<T> lock(){
			Xshared_ptr<T> tem(ref);
			return tem;
		}
		void swap(Xweak_ptr<T>& other){
			swap(ref, other.ref);
		}
		void reset(){
			ref->w_increase();
			ref = nullptr;
		}
	};
}