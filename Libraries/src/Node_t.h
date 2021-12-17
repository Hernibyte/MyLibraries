#ifndef NODE_T_H
#define NODE_T_H

namespace My {

	template <typename T>
	class Node_t {
	public:
		using ValueType = T;

		Node_t* prevNode;
		Node_t* nextNode;
		ValueType _value;
	};

}

#endif // !NODE_T_H
