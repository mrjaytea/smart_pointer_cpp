// TODO: Implement the output operator<< for SmartPtr

/*
    If sp is not null
        outputs to os the string "SmartPtr(",
        followed by the object pointed to by sp.ptr, 
        then by a ",", then by the number of SmartPtr instances containing the address sp.ptr, 
        finally by ")". The object pointed to by sp.ptr should be output by invoking operator<<.

    Else
        outputs to os the string "SmartPtr()".

    For example: 
        if sp.ptr points to a string "Hello World" && two instances of SmartPtr holding the same address, 
            os << sp should output "SmartPtr(Hello World,2)" to os.

*/

template<typename T>
inline ostream& operator<<(ostream& os, const SmartPtr<T>& sp) {
    os << "SmartPtr(";
    if(!sp.is_null())
        os << *(sp.ptr) << "," << *(sp.count);

    os << ")";
    return os;
}