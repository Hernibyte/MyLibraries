#ifndef NODE_T_H
#define NODE_T_H

namespace My {

	template <typename T>
	class Node_t {
	public:
		using ValueType = T;

		Node_t() {
			_prevNode = nullptr;
			_nextNode = nullptr;
			_value = NULL;
		}
		Node_t(ValueType&& value) {
			_prevNode = nullptr;
			_nextNode = nullptr;
			_value = std::move(value);
		}

		Node_t(ValueType const& value, Node_t<ValueType>* prevNode, Node_t<ValueType>* nextNode) {
			_prevNode = prevNode;
			_nextNode = nextNode;
			_value = value;
		}

		Node_t<ValueType>* _prevNode;
		Node_t<ValueType>* _nextNode;
		ValueType _value;
	};

}

#endif // !NODE_T_H
