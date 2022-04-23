// TODO: Implement the member functions of SmartPtr (Part (A), except the output operator)
template<typename T>
inline SmartPtr<T>::SmartPtr() {
    ptr = nullptr;
    count = nullptr;
}

template<typename T>
inline SmartPtr<T>::SmartPtr(const T & val) {
    ptr = new T(val);

    count = new unsigned int;
    *count = 1;
}

template<typename T>
inline SmartPtr<T>::SmartPtr(const SmartPtr<T>& that) {
    this->ptr = that.ptr;
    this->count = that.count;
    if(this->count) *(this->count) += 1;
}
        

template<typename T>
inline SmartPtr<T>::~SmartPtr() {
    if (ptr && count) {
        if (*count == 1) {
            delete ptr;
            delete count;
        }
    }
}

template<typename T>
inline SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& that) {
    if (that.ptr && (this != &that)) {
        if (this->count && *(this->count) == 1) {
            delete this->ptr;
            delete this->count;
        }

        this->ptr = that.ptr;
        this->count = that.count;
        *(this->count) += 1;
    }
    return *this;
}

template<typename T>
inline void SmartPtr<T>::set(const T & val) {
    if (ptr) {
        if (*count == 1) {
            delete ptr;
        }

        ptr = new T(val);
        *count = 1;
    } else {
        ptr = new T(val);
        count = new unsigned int;
        *count = 1;
    }
   
    
}

template<typename T>
inline void SmartPtr<T>::unset() {
    if (ptr) {
        *count -= 1;
    }

    if (*count == 0) {
        delete ptr;
        delete count;
    }
    else {
        ptr = nullptr;
        count = nullptr;
    }
}

template<typename T>
inline bool SmartPtr<T>::is_null() const {
    if (ptr == nullptr) return true;
    else return false;
}

template<typename T>
inline bool SmartPtr<T>::operator==(const SmartPtr<T>& that) const {
    if (this->ptr == that.ptr) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
inline bool SmartPtr<T>::operator!=(const SmartPtr<T>& that) const {
    if (this->ptr != that.ptr) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline T &SmartPtr<T>::operator*() const {
    return *(this->ptr);
}

template<typename T>
inline T * SmartPtr<T>::operator->() const {
    return this->ptr;
}

