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