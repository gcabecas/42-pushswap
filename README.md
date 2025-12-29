*This project has been created as part of the 42 curriculum by gcabecas, ndi-tull.*

# Push_swap

## Description

Push_swap is a sorting algorithm project where the goal is to sort a stack of integers using a limited set of operations, with the minimum number of moves possible. The project implements four different sorting strategies with varying complexity classes, and can automatically select the most efficient strategy based on the initial disorder of the data.

The program takes a list of integers as input and outputs a sequence of operations that will sort the stack in ascending order. It features:
- Four distinct sorting algorithms (Simple, Medium, Complex, and Adaptive)
- A disorder metric to measure how unsorted the initial stack is
- Performance benchmarking mode with detailed statistics
- Compliance with Big-O complexity requirements

## Instructions

### Compilation

```bash
make
```

This will generate the `push_swap` executable.

### Usage

Basic usage:
```bash
./push_swap [numbers...]
```

With strategy selection:
```bash
./push_swap --simple [numbers...]    # Force O(n²) algorithm
./push_swap --medium [numbers...]    # Force O(n√n) algorithm
./push_swap --complex [numbers...]   # Force O(n log n) algorithm
./push_swap --adaptive [numbers...]  # Auto-select based on disorder (default)
```

With benchmark mode (can be combined with any strategy, order doesn't matter):
```bash
./push_swap --bench [numbers...]
./push_swap --bench --complex [numbers...]
./push_swap --complex --bench [numbers...]   # Same as above
./push_swap [numbers...] --bench --simple    # Order is flexible
```

### Examples

```bash
# Sort a small list
./push_swap 3 2 1 5 4

# Sort 100 random numbers and count operations
./push_swap $(shuf -i 1-100 -n 100) | wc -l

# Benchmark with specific strategy
./push_swap --bench --complex 4 67 3 87 23

# Show only benchmark stats (hide operations on stdout)
./push_swap --bench 3 2 1 5 4 > /dev/null

# Save operations to file while seeing benchmark
./push_swap --bench 3 2 1 5 4 > operations.txt
```

### Output Streams

The program uses two output streams:
- **stdout (standard output)**: Contains the sequence of operations (sa, pb, ra, etc.)
  - This is what you redirect with `>` or pipe with `|`
  - Used by checkers to verify the sorting

- **stderr (standard error)**: Contains benchmark information (when `--bench` is used)
  - Format: `[bench] disorder: X.XX%`, operation counts, etc.
  - Always visible in terminal unless redirected with `2>`
  - Allows you to see stats while piping operations to a checker

Examples:
```bash
# See only operations (no benchmark stats)
./push_swap 3 2 1

# See both operations and benchmark stats
./push_swap --bench 3 2 1

# Hide operations, see only benchmark stats
./push_swap --bench 3 2 1 > /dev/null

# Count operations while seeing benchmark stats
./push_swap --bench 3 2 1 | wc -l

# Hide benchmark stats, see only operations
./push_swap --bench 3 2 1 2> /dev/null
```

### Available Operations

- `sa` / `sb` / `ss` : Swap first two elements
- `pa` / `pb` : Push from one stack to another
- `ra` / `rb` / `rr` : Rotate (shift up)
- `rra` / `rrb` / `rrr` : Reverse rotate (shift down)

## Algorithms

### 1. Simple Algorithm - O(n²)

**Type:** Selection sort adaptation

**Description:** Iteratively finds the minimum element in stack A and pushes it to stack B, then pushes everything back to A in sorted order.

**When used:**
- When forced with `--simple` flag
- In adaptive mode when disorder < 0.2 (nearly sorted data)

**Complexity:**
- Time: O(n²) - for each element, we search through remaining elements
- Space: O(1) - uses only the two stacks
- Operations: ~n²/2 for random data

**Justification:** Simple and efficient for small or nearly-sorted datasets. The overhead of more complex algorithms would be greater for these cases.

### 2. Medium Algorithm - O(n√n)

**Type:** Chunk-based sorting

**Description:** Divides the numbers into √n chunks based on their rank. Pushes elements to stack B in chunks, then intelligently pushes them back to A in sorted order by always selecting the element with minimal cost.

**When used:**
- When forced with `--medium` flag
- In adaptive mode when 0.2 ≤ disorder < 0.5 (moderately unsorted)

**Complexity:**
- Time: O(n√n) - √n chunks, each taking O(n) operations
- Space: O(1) - uses only the two stacks
- Operations: ~3n√n for random data

**Justification:** Balances complexity and efficiency for medium-sized datasets. Better than O(n²) for larger inputs while being simpler to implement than O(n log n) algorithms.

### 3. Complex Algorithm - O(n log n)

**Type:** Radix sort (LSD - Least Significant Digit)

**Description:** Normalizes values to indices (0 to n-1), then sorts by examining each bit position. For each bit, elements with bit=0 are pushed to B, then all are pushed back to A, ensuring stability.

**When used:**
- When forced with `--complex` flag
- In adaptive mode when disorder ≥ 0.5 (highly unsorted)

**Complexity:**
- Time: O(n log n) - log₂(n) passes, each taking O(n) operations
- Space: O(1) - uses only the two stacks
- Operations: ~2n log₂(n) for any data

**Justification:** Most efficient for large, highly disordered datasets. The logarithmic factor makes it scale well. Radix sort was chosen for its stability and predictable performance.

### 4. Adaptive Algorithm

**Type:** Strategy selector

**Description:** Measures the disorder of the input stack and automatically selects the most appropriate algorithm:
- **disorder < 0.2** → Simple (O(n²))
- **0.2 ≤ disorder < 0.5** → Medium (O(n√n))
- **disorder ≥ 0.5** → Complex (O(n log n))

**Disorder calculation:** Ratio of inverted pairs to total pairs in the stack.

**Justification:** Optimizes performance by matching the algorithm to the data characteristics. Nearly-sorted data doesn't benefit from complex algorithms, while random data requires them.

## Performance Benchmarks

Target operations for passing evaluation:
- **100 numbers:** < 700 operations (excellent) / < 1500 (good) / < 2000 (pass)
- **500 numbers:** < 5500 operations (excellent) / < 8000 (good) / < 12000 (pass)

## Resources

### Documentation & References
- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [radix explanation](https://www.youtube.com/watch?v=Y95a-8oNqps)

### AI Usage
AI was used in the following parts of the project:
- **README.md creation:** Assistance with structure and formatting of this documentation

No AI-generated code was directly used in the implementation. All algorithms were coded and understood by the team members.

## Project Structure

```
.
├── Makefile
├── README.md
├── pushswap.h           # Main header file
├── main.c               # Entry point and strategy selection
├── init.c               # Initialization and parsing
├── error.c              # Error handling
├── flag.c               # Command-line flag parsing
├── disorder.c           # Disorder calculation
├── simple.c             # O(n²) algorithm
├── medium.c             # O(n√n) algorithm
├── medium_utils.c       # Medium algorithm helpers
├── complex.c            # O(n log n) algorithm
├── complex_utils.c      # Complex algorithm helpers
├── solver_utils.c       # Common sorting utilities
├── push.c               # Push operations (pa, pb)
├── swap.c               # Swap operations (sa, sb, ss)
├── rotate.c             # Rotate operations (ra, rb, rr)
├── reverse_rotate.c     # Reverse rotate operations (rra, rrb, rrr)
├── stck_utils.c         # Stack manipulation utilities
├── stats.c              # Benchmark statistics
├── stats_utils.c        # Statistics helpers
├── utils.c              # General utilities
└── ft_printf.c          # Custom printf implementation
```

## Contributors

### gcabecas
- Project architecture and structure
- Simple algorithm (O(n²))
- Complex algorithm (O(n log n))
- Adaptive strategy selector
- Disorder calculation
- Parsing and error handling
- Stack operations (push, swap, rotate)
- Statistics and benchmark system
- Main program flow

### ndi-tull
- Medium algorithm (O(n√n))
- Chunk-based sorting implementation
- Cost calculation for element positioning

Both contributors participated in:
- Algorithm design discussions
- Testing and debugging
- Performance optimization
- Documentation

