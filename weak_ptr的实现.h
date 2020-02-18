#pragma once
//ģ�廯������������
//���췽�� ��ֵһ��ָ��
//���������ͷ�ָ��
//����׼��ֵ���죨ת���ڲ�����Ȩ��
//����׼���Ƹ���
//reset �ͷ�֮ǰ�ģ������ָ��
//release()�ͷſ���Ȩ����ָ��
//operator*()ģ��ָ����ʷ���
//operator->() ģ��ָ���ͷʽ���ʷ���
//get() ���ָ��ָ���ָ��
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
			r_cout--;//��Ϊ������ö�����ʱ����Ϊ1
			if (r_cout == 0){
				delete obj;//�ͷ�ָ�����
				obj = nullptr;
				//��wҲΪ0���ͷ�����
				if (w_cout == 0){
					delete this;//�ͷŵ�ǰ���ö���
				}
			}
		}
		inline void w_reduce(){
			w_cout--;//��Ϊ������ö�����ʱ����Ϊ1
			if (w_cout == 0 && r_cout == 0){//ǿ����û�в��ͷ�
				delete this;//�ͷŵ�ǰ���ö���
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
	//��ǰ���� ����ᱨXu����ģ��Ĵ���
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
		Xshared_ptr(const Xshared_ptr<T> &other){//otherΪ��������
			ref = other->ref;
			if (ref){
				ref->increase();
			}
		}
		Xshared_ptr(const Xshared_ptr<T> &&other){//�ƶ�����ֱ�ӿ��Խ�������
			swap(ref, other->ref);
		}
		Xshared_ptr& operator=(const Xshared_ptr<T>&other){//1.����ֵ���ò��ܲ��� 
			if (ref){
				ref->reduce();//ָ�뱻��ֵ�������ڸ�����һ����������
			}
			ref = other->ref;
			if (ref){
				ref->increase();
			}
		}
		Xshared_ptr& operator=(const Xshared_ptr<T>&&other){//�Ѵ������ĸ���
			if (ref){
				ref->reduce();
			}
			ref = other->ref;
			other.ref = nullptr;//ָ��û��������һ������
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


	//Xweak_ptr��ʵ��
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