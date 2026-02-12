# Go Solutions

This directory contains LeetCode solutions implemented in Go.

## Solutions

1. [Two Sum](1_two_sum.go) - Easy

## Running Solutions

**Note:** These files are formatted for direct LeetCode submission and do not include `package` declarations or `main()` functions.

To test solutions locally, you have a few options:

1. **Copy into LeetCode's editor** - The files are ready for direct submission
2. **Create a test file** - Create a separate `*_test.go` file with package and test cases
3. **Use Go Playground** - Copy the function to [play.golang.org](https://play.golang.org)

Example test file (`1_two_sum_test.go`):
```go
package main

import "testing"

func TestTwoSum(t *testing.T) {
    nums := []int{2, 7, 11, 15}
    target := 9
    result := twoSum(nums, target)
    expected := []int{0, 1}
    
    if len(result) != 2 || result[0] != expected[0] || result[1] != expected[1] {
        t.Errorf("Expected %v, got %v", expected, result)
    }
}
```

## Tips for Go Solutions

- Follow Go naming conventions and idioms
- Use built-in types effectively
- Include proper documentation comments
- Leverage Go's simplicity for clean code

## Common Patterns

- Hash Maps: `map[K]V`
- Arrays/Slices: `[]T`
- Custom Data Structures: Define as needed
- Sorting: `sort` package
- Heaps: `container/heap` package
