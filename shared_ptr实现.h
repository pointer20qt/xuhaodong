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
	public:
		Ref() = default;
		Ref(T* target) :obj(target), r_cout(1){

		}
		inline void reduce(){
			r_cout--;//因为这个引用对象建立时就置为1
			if (r_cout == 0){
				delete obj;//释放指向对象
				delete this;//释放当前引用对象
			}
		}
		inline void increase(){
			r_cout++;
		}
		T* get(){
			return obj;
		}
		int getCout(){
			return r_cout;
		}
	};
	template<class T>
	class Xshared_ptr{
		Ref* ref = nullptr;
	public:
		Xshared_ptr() = default;
		Xshared_ptr(T* newP){
			ref = new Ref<T>(newP);
		}
		~Xshared_ptr(){
			if (ref){
				ref->reduce();
			}
		}
		Xshared_ptr(const Xshared_ptr &other){//other为被拷对象
			ref = other->ref;
			if (ref){
				ref->increase();
			}
		}
		Xshared_ptr(const Xshared_ptr &&other){//移动构造直接可以交换函数
			swap(ref, other->ref);
		}
		Xshared_ptr& operator=(const Xshared_ptr&other){//1.返回值引用才能操作 
			if (ref){
				ref->reduce();//指针被赋值后引用内个数减一或析构对象
			}
			ref = other->ref;
			if (ref){
				ref->increase();
			}
		}
		Xshared_ptr& operator=(const Xshared_ptr&&other){//把传进来的搞空喽
			if (ref){
				ref->reduce();
			}
			ref = other->ref;
			other.ref = nullptr;//指针没丢传给另一个对象
			return *this;
		}
		void swap(Xshared_ptr &other){
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
}