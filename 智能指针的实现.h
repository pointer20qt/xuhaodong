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