open Curry;

// look at some built in types 
let name: string = "Alex";
let age: int = 30;
let height: float = 180.39;
let lovesToCode: bool = true;

// Variant type
type breakfastFood = | Smoothie | Oats;

let smoothie: option(breakfastFood) = Some(Smoothie);

let whatsForBreakfast = (item: option(breakfastFood)): unit => {
    switch(item) {
        | Some(Smoothie) => Js.log("we're having smoothies!")
        | Some(Oats) => Js.log("we're having oats!")
        | None => Js.log("No breakfast this morning :(")
    }
};

type person = {
    name: string,
    age: int,
    height: float
};

let alex = { name, age, height };

// list
let collection: list('a) = [1,2,3];

let printNumbers = (list: list('a)): list(unit) => {
    list |> List.map(number => Js.log(number))
}

let addOne = (list: list(int)) => {
    list |> List.map(number => number + 1)
}

// function pipes
collection |> addOne |> printNumbers;

let interpolated: string = {j| $name is $age years old and is $height cm tall. |j};

// named arguments 
let sum = (~a: int, ~b: int): int => a + b;
sum(~a=1, ~b=2);

// currying
let addTofive: (int) => (int) = currySum(5);
let seven: int = addTofive(2);

// recursive funcs
let rec recursiveFunc = (number: int): unit => {

    // mutable ref
    let countdown = ref(number);

    while (countdown.contents > 0) {
        // gopher / walrus syntax updates the ref.contents which holds the value
        countdown := countdown.contents - 1;
        recursiveFunc(countdown.contents);
    }
}

recursiveFunc(3);
