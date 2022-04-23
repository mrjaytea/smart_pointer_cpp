// TODO: Implement the output operator<< for Node
template<typename T>
inline ostream & operator<<(ostream & os, const Node<T>& n) {
	os << "Node(";
    os << *n << ",{";

    for (int i = 0; i < n.size(); i++) {

        if (true) {
            if (!(n[i]).is_null()) {
                os << **(n[i]);
                if (!(n[i+1]).is_null() && (n.size() - i) > 1) os << ",";
            }
            
        }
    }
 
    os << "}";
    os << ")";
    return os;
}