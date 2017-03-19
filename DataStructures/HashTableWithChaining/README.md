# Chaining

- Chaining is a possible way to resolve collisions.
- Each slot of the array contains a link to a singly-linked list, containing key-value pairs with the same hash.
- New key-value pairs are added to the end of the list.
- Lookup algorithm searches through the list to find matching key
- Initially table slots contain nulls.
- List is being created, when value with the certain hash is added for the first time.

# Complexity analysis
- Assuming, that hash function distributes hash codes uniformly and table allows dynamic resizing,
amortized complexity of insertion, removal and lookup operations is constant.
- Actual time, taken by those operations linearly depends on table's load factor.

- Note: Even Substantially overloaded hash table, based on chaining, shows well performance.
- Assume hash table with 1000 slots storing 100000 items (load factor is 100).
- It requires a bit more memory (size of the table), than a singly-linked list, but all basic
operations will be done about 1000 times faster on an average.
- Draw attention, that computational complexity of both singly-linked list and constant-sized hash table is O(n)/

# Chaining vs Open addressing.
## Chaining

*Collision Resolution*: Using external data structure (linked list)
*Memory waster*
