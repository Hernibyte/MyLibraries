#ifndef LIST_T_H
#define LIST_T_H

#include <stdexcept>
#include "Node_t.h"
#include <iostream>

namespace My {

	template <typename T>
	class List_t {
	public:
		using value_type = T;
		using node = Node_t<value_type>;

		List_t() {
			_firstNode->_nextNode = _lastNode;
			_firstNode->_prevNode = nullptr;

			_lastNode->_prevNode = _firstNode;
			_lastNode->_nextNode = nullptr;
		}

		node* r_push_back(value_type&& value) {
			node* _node = new node(std::move(value), _lastNode->_prevNode, _lastNode);
			_lastNode->_prevNode->_nextNode = _node;
			_lastNode->_prevNode = _node;

			_size++;
			return _node;
		}
		node* r_push_back(value_type const& value) {
			return r_push_back(value_type{ value });
		}

		node* r_push_front(value_type&& value) {
			node* _node = new node(std::move(value), _firstNode, _firstNode->_nextNode);
			_firstNode->_nextNode->_prevNode = _node;
			_firstNode->_nextNode = _node;

			_size++;
			return _node;
		}
		node* r_push_front(value_type const& value) {
			return r_push_front(value_type{ value });
		}

		node* r_insert(int position, value_type&& value) {
			node* _in_position_node = n_find(position);
			node* _node = new node(std::move(value), _in_position_node->_prevNode, _in_position_node);

			_in_position_node->_prevNode->_nextNode = _node;
			_in_position_node->_prevNode = _node;

			_size++;
			return _node;
		}
		node* r_insert(int position, value_type const& value) {
			return r_insert(position, value_type{ value });
		}

		node* r_inverse_insert(int position, value_type&& value) {
			node* _in_position_node = n_find(position);
			node* _node = new node(std::move(value), _in_position_node, _in_position_node->_nextNode);

			_in_position_node->_nextNode->_prevNode = _node;
			_in_position_node->_nextNode = _node;

			_size++;
			return _node;
		}
		node* r_inverse_insert(int position, value_type const& value) {
			return r_inverse_insert(position, value_type{ value });
		}

		void constexpr push_back(value_type&& value) {
			r_push_back(value);
		}
		void constexpr push_back(value_type const& value) {
			push_back(value_type{ value });
		}

		void constexpr push_front(value_type&& value) {
			r_push_front(value);
		}
		void constexpr push_front(value_type const& value) {
			push_front(value_type{ value });
		}

		void constexpr insert(int position ,value_type&& value) {
			r_insert(position, value);
		}
		void constexpr insert(int position, value_type const& value) {
			insert(position, value_type{ value });
		}

		void constexpr inverse_insert(int position, value_type&& value) {
			r_inverse_insert(position, value);
		}
		void constexpr inverse_insert(int position, value_type const& value) {
			inverse_insert(position, value_type{ value });
		}

		bool constexpr pop_back() noexcept {
			if (size() == 0) return false;
			_lastNode->_prevNode = _lastNode->_prevNode->_prevNode;
			delete _lastNode->_prevNode->_nextNode;
			_lastNode->_prevNode->_nextNode = _lastNode;

			_size--;
			return true;
		}
		bool constexpr pop_front() noexcept {
			if (size() == 0) return false;
			_firstNode->_nextNode = _firstNode->_nextNode->_nextNode;
			delete _firstNode->_nextNode->_prevNode;
			_firstNode->_nextNode->_prevNode = _firstNode;

			_size--;
			return true;
		}

		value_type constexpr front() noexcept {
			if (_firstNode->_nextNode == _lastNode) return NULL;
			return _firstNode->_nextNode->_value;
		}
		value_type constexpr back() noexcept {
			if (_lastNode->_prevNode == _firstNode) return NULL;
			return _lastNode->_prevNode->_value;
		}

		value_type constexpr front_exp() {
			if (_firstNode->_nextNode == _lastNode) throw std::runtime_error("The list is empty");
			return _firstNode->_nextNode->_value;
		}
		value_type constexpr back_exp() {
			if (_lastNode->_prevNode == _firstNode) throw std::runtime_error("The list is empty");
			return _lastNode->_prevNode->_value;
		}

		bool constexpr empty() noexcept {
			return _size == 0;
		}

		std::size_t constexpr size() const noexcept {
			return _size;
		}

		bool constexpr erase(node* _node) {
			if (size() == 0) return false;
			_node->_nextNode->_prevNode = _node->_prevNode;
			_node->_prevNode->_nextNode = _node->_nextNode;
			delete _node;

			_size--;
			return true;
		}

		value_type constexpr find(int position) {
			if (size() == 0) throw std::runtime_error("the list is empty");
			if (position <= 0 || position > size()) throw std::runtime_error("Position out of range");

			return r_value_by_position(position);
		}
		node* n_find(int position) {
			if (size() == 0) throw std::runtime_error("the list is empty");
			if (position <= 0 || position > size()) throw std::runtime_error("Position out of range");

			return r_node_by_position(position);
		}

		value_type constexpr at(int position) noexcept {
			if (size() == 0) return NULL;
			if (position <= 0 || position > size()) return NULL;

			return r_value_by_position(position);
		}
		node* n_at(int position) noexcept {
			if (size() == 0) return nullptr;
			if (position <= 0 || position > size()) return nullptr;

			return r_node_by_position(position);
		}

		node* n_find_value(value_type&& value) {
			if (size() == 0) throw std::runtime_error("the list is empty");

			return r_node_by_value(value);
		}
		node* n_find_value(value_type const& value) {
			if (size() == 0) throw std::runtime_error("the list is empty");

			return r_node_by_value(value);
		}

		node* n_at_value(value_type&& value) noexcept {
			if (size() == 0) return nullptr;

			return r_node_by_value(value);
		}
		node* n_at_value(value_type const& value) noexcept {
			if (size() == 0) return nullptr;

			return r_node_by_value(value);
		}

		bool constexpr replace(int position, value_type&& value) noexcept {
			node* _node = n_at(position);
			if (_node == nullptr) return false;

			_node->_value = std::move(value);
			return true;
		}
		bool constexpr replace(int position, value_type const& value) noexcept {
			return replace(position, value_type{ value });
		}

		bool constexpr remove(int position) noexcept {
			node* _node = n_at(position);
			return erase(_node);
		}

		void constexpr clear_all() {
			throw std::runtime_error("Not implemented");
		}

		value_type constexpr operator[](int index) {
			if (size() == 0) throw std::runtime_error("the list is empty");
			if (index < 0 || index >= size()) throw std::runtime_error("Position out of range");

			return r_value_by_position(index + 1);
		}

	private:
		node* _firstNode = new node();
		node* _lastNode = new node();
		std::size_t _size = 0;

		node* r_node_by_position(int position) noexcept {
			int count = 1;
			node* _node = _firstNode->_nextNode;
			for (int i = 0; i <= size(); i++) {
				if (count == position) return _node;
				_node = _node->_nextNode;
				count++;
			}
			return nullptr;
		}
		value_type constexpr r_value_by_position(int position) noexcept {
			return r_node_by_position(position)->_value;
		}

		node* r_node_by_value(value_type&& value) {
			node* _node = _firstNode->_nextNode;
			for (int i = 0; i <= size(); i++) {
				if (_node->_value == std::move(value)) return _node;
				_node = _node->_nextNode;
			}
		}
		node* r_node_by_value(value_type const& value) {
			node* _node = _firstNode->_nextNode;
			for (int i = 0; i <= size(); i++) {
				if (_node->_value == value) return _node;
				_node = _node->_nextNode;
			}
		}
	};

}

#endif // !LIST_H
