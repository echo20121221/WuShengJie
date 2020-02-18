#pragma once
template<class T>
class L_autoPtr{
	T* obj = nullptr;
public:
	L_autoPtr(T* ptr):obj(ptr){
	}
	L_autoPtr() = default;
	~L_autoPtr(){
		delete obj;
	}
	L_autoPtr(L_autoPtr<T>&ptr){
		obj = ptr.obj;
		ptr.obj=nullptr
	}
	L_autoPtr& operator=(L_autoPtr<T>&ptr){
		
		obj = ptr.release();
		return *this;
	}
	void reset(T* newptr=nullptr){
		delete obj;
		obj = newptr;
	}
	T* release(){
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	T& operator*(){
		return *obj;
	}
};