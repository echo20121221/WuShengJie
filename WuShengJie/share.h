#pragma once
namespace lan{
	template<class T>
	class L_autoPtr{
		T* obj = nullptr;
	public:
		L_autoPtr(T* ptr) :obj(ptr){
		}
		L_autoPtr() = default;
		~L_autoPtr(){
			delete obj;
		}
		L_autoPtr(L_autoPtr<T>&ptr){
			obj = ptr.obj;
			ptr.obj = nullptr
		}
		L_autoPtr& operator=(L_autoPtr<T>&ptr){

			obj = ptr.release();
			return *this;
		}
		void reset(T* newptr = nullptr){
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
	//资源计数类
	template<class T>
	class Ref{
		//当前资源计数
		int r_count;
		T* object;
	public:
		Ref(T* target) :object(target){
			++t_count;
		}
		inline void increase(){
			r_count++;
		}
		inline void reduce(){
			r_count--;
			if (r_count == 0){
				delete this;
			}
		}
		T* get(){
			return object;
		}
		int getCount(){
			return count;
		}
	};
	//
	template<class T>class LSharedPtr{
		Ref* ref = nullptr;
	public:
		LSharedPtr() = default;
		LSharedPtr(T* newP){
			Ref = new Ref<T>(newP);
		}
		LSharedPtr(const LSharedPtr& other){
			ref = other.ref;
			if (ref){
				ref->increase();
			}
		}
		LSharedPtr(LSharedPtr&& other){
			swap(ref, other.ref)
		}
		LSharedPtr& operator=(const LSharedPtr& other){
			if (ref){
				ref->reduce();
			}
			ref = other.ref;
			if (ref){
				ref->increase();
			}
			return *this;
		}
		LSharedPtr& operator=(LSharedPtr&& other){
			if (ref){
				ref->reduce();
			}
			ref = other.ref;
			other.ref = nullptr;
			return *this;
		}
		void swap(LSharedPtr&other){
			swap(ref, other.ref);
		}
		void reset(T* target=nullptr){
			if (ref){
				ref->reduce();
			}
			if (target != nullptr){
				ref = new Ref(target);
			}
			else{
				ref = nullptr;
			}			
		}
		T& operator*(){
			if (ref){
				return ref->get();
			}
			else{
				return *(T*)nullptr;
			}

		}
		T*operator->(){
			if (ref){
				return ref->get();
			}
			else{
				return (T*)nullptr;
			}
		}
		T*get(){
			if (ref){
				return ref->get();
			}
			else{
				return (T*)nullptr;
			}
		}
		int use_count(){
			if (ref){
				return ref->getCount();
			}
			else{
				return 0;
			}
		}
		bool unique(){
			if (ref){
				return ref->getCount() == 1;
			}
			else{
				false;
			}
		}
		operator bool(){
			return ref != nullptr;
		}
		~LSharedPtr(){
			if (ref)
			{
				ref->reduce();
			}
		}
	
	};

}
