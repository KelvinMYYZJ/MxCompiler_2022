#pragma once
#include "my_exception.h"
using std::pair;
template <class T>
class LinkedList {
 private:
  struct LinkedListNode {
    T *const val_;
    LinkedListNode *next;
    LinkedListNode *last;
    LinkedListNode(T *_val, LinkedListNode *_next, LinkedListNode *_last) : val_(_val), next(_next), last(_last) {}
    LinkedListNode(const T &obj) : LinkedListNode(new T(obj), nullptr, nullptr) {}
    LinkedListNode() : LinkedListNode(nullptr, nullptr, nullptr) {}
    LinkedListNode(const LinkedListNode &other) : LinkedListNode(other.val) {}
    ~LinkedListNode() {
      if (val_) delete val_;
    }
  };
  LinkedListNode *const head_, *const tail_;
  size_t size_;
  void InsertBefore_(LinkedListNode *node, LinkedListNode *pos) {
    node->next = pos;
    node->last = pos->last;
    pos->last->next = node;
    pos->last = node;
    ++size_;
  }

 public:
  /**
   * see BidirectionalIterator at CppReference for help.
   *
   * if there is anything wrong throw MyException("invalid_iterator in linked
   * hashmap")   *     like it = linked_hashmap.begin(); --it; or it =
   * linked_hashmap.end(); ++end();
   */
  class const_iterator;
  class iterator {
    friend class const_iterator;
    friend class LinkedList<T>;

   private:
    /**
     * TODO add data members
     *   just add whatever you want.
     */
    LinkedList *parent_;
    LinkedListNode *pos_;

   public:
    // The following code is written for the C++ type_traits library.
    // Type traits is a C++ feature for describing certain properties of a
    // type. For instance, for an iterator, iterator::value_type is the type
    // that the iterator points to. STL algorithms and containers may use
    // these type_traits (e.g. the following typedef) to work properly. See
    // these websites for more information:
    // https://en.cppreference.com/w/cpp/header/type_traits About value_type:
    // https://blog.csdn.net/u014299153/article/details/72419713 About
    // iterator_category: https://en.cppreference.com/w/cpp/iterator
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = value_type *;
    using reference = value_type &;
    using iterator_category = std::output_iterator_tag;

    inline iterator(LinkedList *parent, LinkedListNode *pos) : parent_(parent), pos_(pos) {}
    inline iterator() : iterator(nullptr, nullptr) {}

    inline iterator(const iterator &other) : parent_(other.parent_), pos_(other.pos_) {}

    iterator &operator=(const iterator &other) {
      parent_ = other.parent_;
      pos_ = other.pos_;
      return *this;
    }
    /**
     * TODO iter++
     */
    iterator operator++(int) {
      iterator tmp = *this;
      ++*this;
      return tmp;
    }
    /**
     * TODO ++iter
     */
    iterator &operator++() {
      if (!pos_ || !pos_->next)  // is tail(end)
        throw MyException("invalid_iterator in linked hashmap");
      pos_ = pos_->next;
      return *this;
    }
    /**
     * TODO iter--
     */
    iterator operator--(int) {
      iterator tmp = *this;
      --*this;
      return tmp;
    }
    /**
     * TODO --iter
     */
    iterator &operator--() {
      if (!pos_ || !pos_->last->last)  // is head(begin)
        throw MyException("invalid_iterator in linked hashmap");
      pos_ = pos_->last;
      return *this;
    }
    /**
     * a operator to check whether two iterators are same (pointing to the
     * same memory).
     */
    value_type &operator*() const {
      if (!pos_ || !pos_->val_) throw MyException("invalid_iterator in linked hashmap");
      return *pos_->val_;
    }
    bool operator==(const iterator &rhs) const { return pos_ == rhs.pos_; }
    bool operator==(const const_iterator &rhs) const { return pos_ == rhs.pos_; }
    /**
     * some other operator for iterator.
     */
    inline bool operator!=(const iterator &rhs) const { return pos_ != rhs.pos_; }
    inline bool operator!=(const const_iterator &rhs) const { return pos_ != rhs.pos_; }

    /**
     * for the support of it->first.
     * See
     * <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/>
     * for help.
     */
    inline value_type *operator->() const noexcept {
      // if (!pos_ || !pos_->val_) throw MyException("invalid_iterator in linked
      // hashmap");
      return pos_->val_;
    }
  };

  class const_iterator {
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = value_type *;
    using reference = value_type &;
    friend class iterator;
    friend class LinkedList<T>;
    // it should has similar member method as iterator.
    //  and it should be able to construct from an iterator.
   private:
    // data members.
    const LinkedList *parent_;
    const LinkedListNode *pos_;

   public:
    inline const_iterator(const LinkedList *parent, const LinkedListNode *pos) : parent_(parent), pos_(pos) {}
    inline const_iterator() : const_iterator(nullptr, nullptr) {}
    inline const_iterator(const const_iterator &other) : parent_(other.parent_), pos_(other.pos_) {}
    inline const_iterator(const iterator &other) : parent_(other.parent_), pos_(other.pos_) {}
    // And other methods in iterator.

    const_iterator &operator=(const iterator &other) {
      parent_ = other.parent_;
      pos_ = other.pos_;
      return *this;
    }
    /**
     * TODO iter++
     */
    const_iterator operator++(int) {
      const_iterator tmp = *this;
      ++*this;
      return tmp;
    }
    /**
     * TODO ++iter
     */
    const_iterator &operator++() {
      if (!pos_ || !pos_->next)  // is tail(end())
        throw MyException("invalid_iterator in linked hashmap");
      pos_ = pos_->next;
      return *this;
    }
    /**
     * TODO iter--
     */
    const_iterator operator--(int) {
      const_iterator tmp = *this;
      --*this;
      return tmp;
    }
    /**
     * TODO --iter
     */
    const_iterator &operator--() {
      if (!pos_ || !pos_->last->last)  // is head->next(begin())
        throw MyException("invalid_iterator in linked hashmap");
      pos_ = pos_->last;
      return *this;
    }
    const value_type &operator*() const {
      if (!pos_ || !pos_->val_) throw MyException("invalid_iterator in linked hashmap");
      return *pos_->val_;
    }
    bool operator==(const iterator &rhs) const { return pos_ == rhs.pos_; }
    bool operator==(const const_iterator &rhs) const { return pos_ == rhs.pos_; }
    inline bool operator!=(const iterator &rhs) const { return pos_ != rhs.pos_; }
    inline bool operator!=(const const_iterator &rhs) const { return pos_ != rhs.pos_; }
    const inline value_type *operator->() const noexcept {
      // if (!pos_ || !pos_->val_) throw MyException("invalid_iterator in linked
      // hashmap");
      return pos_->val_;
    }
  };

 private:
  void Erase_(LinkedListNode *node) {
    node->last->next = node->next;
    node->next->last = node->last;
    delete node;
    --size_;
  }
  void Copy_(const LinkedList &other) {
    Clear();
    for (const_iterator it = other.cbegin(), ed = other.cend(); it != ed; ++it) PushBack(*it);
  }

 public:
  LinkedList() : head_(new LinkedListNode()), tail_(new LinkedListNode()), size_(0) {
    head_->next = tail_;
    tail_->last = head_;
  }
  LinkedList(const LinkedList &other) : LinkedList() {
    Copy_(other);
    return;
  }
  LinkedList &operator=(const LinkedList &other) {
    if (this == &other) return *this;
    Copy_(other);
    return *this;
  }
  void Clear() {
    while (head_->next != tail_) {
      LinkedListNode *deleting_node = head_->next;
      head_->next = head_->next->next;
      delete deleting_node;
    }
    tail_->last = head_;
    size_ = 0;
    return;
  }
  size_t Size() const { return size_; }
  bool Empty() const { return size_ == 0; }
  void PushBack(const T &obj) {
    LinkedListNode *new_node = new LinkedListNode(obj);
    InsertBefore_(new_node, tail_);
    return;
  }
  void Erase(const iterator &it) {
    Erase_(it.pos_);
    return;
  }
  inline iterator begin() { return iterator(this, head_->next); }
  inline iterator end() { return iterator(this, tail_); }
  inline const_iterator cbegin() const { return const_iterator(this, head_->next); }
  inline const_iterator cend() const { return const_iterator(this, tail_); }
  bool CheckIn(const iterator &obj) const { return obj.parent_ == this; }
  bool CheckIn(const const_iterator &obj) const { return obj.parent_ == this; }
  ~LinkedList() {
    Clear();
    delete head_;
    delete tail_;
  }
};  // namespace sjtu

template <class Key, class T, class Hash = std::hash<Key>, class Equal = std::equal_to<Key>>
class linked_hashmap {
 public:
  /**
   * the internal type of data.
   * it should have a default constructor, a copy constructor.
   * You can use sjtu::linked_hashmap as value_type by typedef.
   */
  typedef pair<const Key, T> value_type;
  using iterator = typename LinkedList<value_type>::iterator;
  using const_iterator = typename LinkedList<value_type>::const_iterator;

 private:
  size_t log_capacity_;
  size_t capacity_;
  constexpr static const double load_factor_ = 0.75;
  // size_t size_;
  Equal equal_;
  typedef typename LinkedList<iterator>::iterator hash_iterator;
  typedef typename LinkedList<iterator>::const_iterator hash_const_iterator;
  LinkedList<value_type> main_list_;
  LinkedList<iterator> **hash_table_;
  size_t GetIndex_(const Key &key) const {
    // refrence: https://www.cnblogs.com/wangshaowei/p/10891116.html
    size_t tmp_ans = Hash()(key);
    tmp_ans ^= (tmp_ans >> 20) ^ (tmp_ans >> 12);
    return (tmp_ans ^ (tmp_ans >> 7) ^ (tmp_ans >> 4)) & capacity_;
  }

  void InsertIterator(const iterator &iter) {
    size_t index = GetIndex_(iter->first);
    if (!hash_table_[index]) {
      hash_table_[index] = new LinkedList<iterator>();
    }
    hash_table_[index]->PushBack(iter);
    return;
  }
  void ReHash_() {
    for (iterator it = main_list_.begin(), ed = main_list_.end(); it != ed; ++it) InsertIterator(it);
    return;
  }

  void DeleteHashTable_() {
    if (hash_table_) {
      for (int i = 0; i < 1 << log_capacity_; ++i)
        if (hash_table_[i]) delete hash_table_[i];
      delete[] hash_table_;
    }
  }

  void SetHashTableEmpty_() { memset(hash_table_, 0, sizeof(LinkedList<iterator> *) * (1 << log_capacity_)); }

  void SetLogCapacity_(size_t log_capacity) {  // Create an empty hash_table_
    DeleteHashTable_();
    log_capacity_ = log_capacity;
    capacity_ = (1 << log_capacity_) - 1;
    hash_table_ = new LinkedList<iterator> *[1 << log_capacity_];
    SetHashTableEmpty_();
    return;
  }
  inline hash_iterator Find_(LinkedList<iterator> &tar_list, const Key &key) const {
    for (auto it = tar_list.begin(), ed = tar_list.end(); it != ed; ++it)
      if (equal_((*it)->first, key)) return it;
    return tar_list.end();
  }
  inline hash_const_iterator Find_(const LinkedList<iterator> &tar_list, const Key &key) const {
    for (hash_const_iterator it = tar_list.cbegin(), ed = tar_list.cend(); it != ed; ++it)
      if (it->first == key) return it;
    return tar_list.cend();
  }

 public:
  /**
   * TODO two constructors
   */
  linked_hashmap()
      : log_capacity_(15),
        capacity_((1 << log_capacity_) - 1),
        main_list_(),
        hash_table_(new LinkedList<iterator> *[1 << log_capacity_]) {
    SetHashTableEmpty_();
  }
  linked_hashmap(const linked_hashmap &other)
      : log_capacity_(other.log_capacity_),
        capacity_(other.capacity_),
        main_list_(other.main_list_),
        hash_table_(new LinkedList<iterator> *[1 << log_capacity_]) {
    SetHashTableEmpty_();
    ReHash_();
  }

  /**
   * TODO assignment operator
   */
  linked_hashmap &operator=(const linked_hashmap &other) {
    if (this == &other) return *this;
    SetLogCapacity_(other.log_capacity_);
    main_list_ = other.main_list_;
    ReHash_();
    return *this;
  }

  /**
   * TODO Destructors
   */
  ~linked_hashmap() {
    DeleteHashTable_();
    return;
  }

  /**
   * TODO
   * access specified element with bounds checking
   * Returns a reference to the mapped value of the element with key
   * equivalent to key. If no such element exists, an exception of type
   * `index_out_of_bound'
   */
  T &at(const Key &key) {
    size_t index = GetIndex_(key);
    if (!hash_table_[index]) throw MyException("index_out_of_bound in linked hashmap");
    auto it = Find_(*hash_table_[index], key);
    if (it == hash_table_[index]->end()) throw MyException("index_out_of_bound in linked hashmap");
    return (*it)->second;
  }
  const T &at(const Key &key) const {
    size_t index = GetIndex_(key);
    if (!hash_table_[index]) throw MyException("index_out_of_bound in linked hashmap");
    hash_const_iterator it = Find_(*hash_table_[index], key);
    if (it == hash_table_[index]->cend()) throw MyException("index_out_of_bound in linked hashmap");
    return (*it)->second;
  }

  /**
   * TODO
   * access specified element
   * Returns a reference to the value that is mapped to a key equivalent to
   * key, performing an insertion if such key does not already exist.
   */
  T &operator[](const Key &key) {
    size_t index = GetIndex_(key);
    if (hash_table_[index]) {
      auto it = Find_(*hash_table_[index], key);
      if (it != hash_table_[index]->end()) return (*it)->second;
    }
    value_type value(key, T());
    main_list_.PushBack(value);
    if (main_list_.Size() > ((1 << log_capacity_) * load_factor_)) {
      SetLogCapacity_(log_capacity_ + 1);
      ReHash_();
    }
    auto tmp_it = main_list_.end();
    --tmp_it;
    InsertIterator(tmp_it);
    return tmp_it->second;
    // return insert(value_type(key, T())).first->second;
  }

  /**
   * behave like at() throw index_out_of_bound if such key does not exist.
   */
  const T &operator[](const Key &key) const { return at(key); }

  /**
   * return a iterator to the beginning
   */
  inline iterator begin() { return main_list_.begin(); }
  inline const_iterator cbegin() const { return main_list_.cbegin(); }

  /**
   * return a iterator to the end
   * in fact, it returns past-the-end.
   */
  inline iterator end() { return main_list_.end(); }
  inline const_iterator cend() const { return main_list_.cend(); }

  /**
   * checks whether the container is empty
   * return true if empty, otherwise false.
   */
  bool empty() const { return main_list_.Empty(); }

  /**
   * returns the number of elements.
   */
  size_t size() const { return main_list_.Size(); }

  /**
   * clears the contents
   */
  void clear() {
    main_list_.Clear();
    SetLogCapacity_(15);
    return;
  }

  /**
   * insert an element.
   * return a pair, the first of the pair is
   *   the iterator to the new element (or the element that prevented the
   * insertion), the second one is true if insert successfully, or false.
   */
  pair<iterator, bool> insert(const value_type &value) {
    const Key &key = value.first;
    size_t index = GetIndex_(key);
    if (hash_table_[index]) {
      auto it = Find_(*hash_table_[index], key);
      if (it != hash_table_[index]->end()) return pair<iterator, bool>(*it, false);
    }
    main_list_.PushBack(value);
    if (main_list_.Size() > ((1 << log_capacity_) * load_factor_)) {
      SetLogCapacity_(log_capacity_ + 1);
      ReHash_();
    }
    auto tmp_it = main_list_.end();
    --tmp_it;
    InsertIterator(tmp_it);
    return pair<iterator, bool>(tmp_it, true);
  }

  /**
   * erase the element at pos.
   *
   * throw if pos pointed to a bad element (pos == this->end() || pos points
   * an element out of this)
   */
  void erase(const iterator &pos) {
    if (!main_list_.CheckIn(pos) || pos == main_list_.end()) throw MyException("index_out_of_bound in linked hashmap");
    const Key &key = pos->first;
    size_t index = GetIndex_(key);
    if (!hash_table_[index]) throw("???");
    auto it = Find_(*hash_table_[index], key);
    if (it == hash_table_[index]->end()) throw("???");
    hash_table_[index]->Erase(it);
    main_list_.Erase(pos);
    return;
  }

  /**
   * Returns the number of elements with key
   *   that compares equivalent to the specified argument,
   *   which is either 1 or 0
   *     since this container does not allow duplicates.
   */
  inline size_t count(const Key &key) const {
    size_t index = GetIndex_(key);
    if (!hash_table_[index]) return 0;
    auto it = Find_(*hash_table_[index], key);
    if (it == hash_table_[index]->cend()) return 0;
    return 1;
  }

  /**
   * Finds an element with key equivalent to key.
   * key value of the element to search for.
   * Iterator to an element with key equivalent to key.
   *   If no such element is found, past-the-end (see end()) iterator is
   * returned.
   */
  inline iterator find(const Key &key) {
    size_t index = GetIndex_(key);
    if (!hash_table_[index]) return end();
    auto it = Find_(*hash_table_[index], key);
    if (it == hash_table_[index]->end()) return end();
    return *it;
  }
  inline const_iterator find(const Key &key) const {
    size_t index = GetIndex_(key);
    if (!hash_table_[index]) return cend();
    auto it = Find_(*hash_table_[index], key);
    if (it == hash_table_[index]->cend()) return cend();
    return *it;
  }
};