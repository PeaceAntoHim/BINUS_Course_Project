package main

import "fmt"

func main() {

	// defer fmt.Print("Done")
	// map_objecet := map[string]string{
	// 	"go": "lang",
	// 	"foo": "moo",
	// }

	// if val, isExist := map_object["foo"]; isExist {
	// 	fmt.Printf("Found %s ", val)
	// 	return
	// }

	// fmt.Print("Finish")

	a := make([]int, 0, 5)
	a = append(a, 10)
	fmt.Print(len(a))
}
