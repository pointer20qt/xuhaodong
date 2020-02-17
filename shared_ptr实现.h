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
	public:
		Ref() = default;
		Ref(T* target) :obj(target), r_cout(1){

		}
		inline void reduce(){
			r_cout--;//��Ϊ������ö�����ʱ����Ϊ1
			if (r_cout == 0){
				delete obj;//�ͷ�ָ�����
				delete this;//�ͷŵ�ǰ���ö���
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
		Xshared_ptr(const Xshared_ptr &other){//otherΪ��������
			ref = other->ref;
			if (ref){
				ref->increase();
			}
		}
		Xshared_ptr(const Xshared_ptr &&other){//�ƶ�����ֱ�ӿ��Խ�������
			swap(ref, other->ref);
		}
		Xshared_ptr& operator=(const Xshared_ptr&other){//1.����ֵ���ò��ܲ��� 
			if (ref){
				ref->reduce();//ָ�뱻��ֵ�������ڸ�����һ����������
			}
			ref = other->ref;
			if (ref){
				ref->increase();
			}
		}
		Xshared_ptr& operator=(const Xshared_ptr&&other){//�Ѵ������ĸ���
			if (ref){
				ref->reduce();
			}
			ref = other->ref;
			other.ref = nullptr;//ָ��û��������һ������
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