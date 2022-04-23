// TODO: Implement the member functions of Node (Part (B), except the output operator)
//             and the graph operations (Part (C))

// Node
template<typename T>
inline Node<T>::Node(const T& val) {
	this->val = val;
}

template<typename T>
inline Node<T>::Node(const Node<T>& that) {
	this->val = that.val;
}

template<typename T>
inline Node<T>::~Node() {
}

template<typename T>
inline T& Node<T>::operator*() {
	return val;
}


template<typename T>
inline const T & Node<T>::operator*() const {
	return val;
}

template<typename T>
inline unsigned int Node<T>::degree() const {
	return 0;
}

template<typename T>
inline unsigned int Node<T>::size() const {
	return size_p;
}

template<typename T>
inline SmartPtr<Node<T>> Node<T>::operator[](unsigned int i) const {
	return out[i];
}

template<typename T>
inline void Node<T>::add(SmartPtr<Node<T>> n) {
	if (n.is_null()) return;
	if (out == nullptr) {
		out = new SmartPtr<Node<T>>[init_capacity * 10];
		size_p = 0;
		capacity = init_capacity * 10;
	}

	out[size_p] = n;

	size_p += 1;
	
}

template<typename T>
inline void Node<T>::remove(SmartPtr<Node<T>> n) {
	if (n.is_null() || out == nullptr) return;
	for (int i = 0; i < size_p; i++) {

		if (out[i] == n) {
			out[i].unset();
		}
	}
}

template<typename T>
inline bool Node<T>::exists(SmartPtr<Node<T>> n) const {
	if (n.is_null() || out == nullptr) return false;

	for (int i = 0; i < size_p; i++) {

		if (out[i] == n) {
			return true;
		}
	}

	return false;
}

template<typename T>
inline SmartPtr<Node<T>> Node<T>::find(T val) const {
	if (out == nullptr) return SmartPtr<Node<T>>();

	for (int i = 0; i < size_p; i++) {
		if (**out[i] == val) {
			return out[i];
		}
	}

	return SmartPtr<Node<T>>();
}

template<typename T>
inline SmartPtr<Node<T>> new_node(const T &val) {
	SmartPtr<Node<T>> *newNode = new SmartPtr<Node<T>>();
	*newNode = SmartPtr<Node<T>>(val);
	return *newNode;
}

template<typename T>
inline void remove_node(SmartPtr<Node<T>> n) {
	if (n.is_null()) return;

	for (int i = 0; i < (*n).size(); i++) {
		if(!((*n)[i]).is_null())
			(*(*n)[i]).remove(n);
	}

}

template<typename T>
inline SmartPtr<Node<T>> find(SmartPtr<Node<T>> root, T val) {
	if (root.is_null()) return SmartPtr<Node<T>>();

	if (**root == val) return *root;

	int i = 0;
	int size = (* root).size();

	while (i < size) {
		SmartPtr<Node<T>> iRoot = *(*root)[i];
		if (**iRoot == val) return *iRoot;
		i++;
	}


	return SmartPtr<Node<T>>();
}

template<typename T>
inline bool reachable(SmartPtr<Node<T>> root, SmartPtr<Node<T>> dest) {
	if (root.is_null() || dest.is_null()) return false;

	int i = 0;
	int j = 0;
	int size = (*root).size();
	int destSize = (*dest).size();

	while (i <= size) {
		if ((*root)[i] == dest) {
			return true;
		}
		while (j <= destSize) {
			if ((*root)[i] == (*dest)[j]) {
				return true;
			}
			j++;
		}
		i++;
	}

	return false;
}

// Graph
template<typename T>
inline void add_edge(SmartPtr<Node<T>> n1, SmartPtr<Node<T>> n2) {
	if (n1.is_null() || n2.is_null()) {
		return;
	} else {
		(*n1).add(n2);
		(*n2).add(n1);
	}
}

template<typename T>
inline void remove_edge(SmartPtr<Node<T>> n1, SmartPtr<Node<T>> n2) {
	if (n1.is_null() || n2.is_null()) {
		return;
	}
	else {
		(*n1).remove(n2);
		(*n2).remove(n1);
	}
}

template<typename T>
inline void remove_graph(SmartPtr<Node<T>> root) {

}

