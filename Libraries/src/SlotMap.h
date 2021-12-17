#ifndef SLOTMAP_H
#define SLOTMAP_H

#include <array>
#include <stdexcept>
#include <cassert>

namespace My {

	template <typename T, std::size_t Capacity, typename indexT = std::uint32_t>
	struct SlotMap {
		using value_type = T;
		using index_type = indexT;
		using gen_type = index_type;
		using key_type = struct { index_type id; gen_type gen; };
		using iterator = value_type*;
		using const_iterator = value_type const*;

		constexpr explicit SlotMap() { clear(); }

		[[nodiscard]] constexpr std::size_t size() const noexcept { return _size; }
		[[nodiscard]] constexpr std::size_t capacity() const noexcept { return Capacity; }

		[[nodiscard]] constexpr key_type push_back(value_type&& value) {
			auto reserved_slot_id = allocate();
			auto& slot = _index[reserved_slot_id];

			_value[slot.id] = std::move(value);
			_erase[slot.id] = reserved_slot_id;

			auto key{ slot };
			key.id = reserved_slot_id;

			return key;
		}
		[[nodiscard]] constexpr key_type push_back(value_type const& value) {
			return push_back(value_type{ value });
		}

		constexpr void clear() noexcept { freelist_init(); }

		constexpr bool erase(key_type key) noexcept {
			if (!is_valid(key)) return false;

			free(key);

			return true;
		}

		[[nodiscard]] constexpr bool is_valid(key_type key) const noexcept {
			if (key.id >= Capacity || _index[key.id].gen != key.gen) return false;
			return true;
		}

		[[nodiscard]] constexpr iterator begin() noexcept { return _value.begin(); }
		[[nodiscard]] constexpr iterator end() noexcept { return _value.begin() + _size; }
		[[nodiscard]] constexpr iterator cbegin() const noexcept { return _value.cbegin(); }
		[[nodiscard]] constexpr iterator cend() const noexcept { return _value.cbegin() + _size; }
	private:
		[[nodiscard]] constexpr index_type allocate() {
			if (_size >= Capacity) throw std::runtime_error("SlotMap is full");
			assert(_freelist < Capacity);

			auto slot_id = _freelist;
			_freelist = _index[slot_id].id;

			auto& slot = _index[slot_id];
			slot.id = _size;
			slot.gen = _generation;

			++_size;
			++_generation;

			return slot_id;
		}
		[[nodiscard]] constexpr void free(key_type key) noexcept {
			assert(is_valid(key));

			auto& slot = _index[key.id];
			auto data_id = slot.id;

			slot.id = _freelist;
			slot.gen = _generation;
			_freelist = key.id;

			if (data_id != _size - 1) {
				_value[data_id] = _value[_size - 1];
				_erase[data_id] = _erase[_size - 1];
				_index[_erase[data_id]].id = data_id;
			}

			++_generation;
			--_size;
		}

		constexpr void freelist_init() noexcept {
			for (index_type i{}; i < _index.size(); ++i)
				_index[i].id = i + 1;
			_freelist = 0;
		}

		index_type _size{};
		index_type _freelist{};
		gen_type _generation{};
		std::array<value_type, Capacity> _value{};
		std::array<key_type, Capacity> _index{};
		std::array<index_type, Capacity> _erase{};
	};
}

#endif // !SLOTMAP_H
