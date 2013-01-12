function even(n) {
    if(n == 0) {
        return function() { return true; };
    } else {
        return function() { return odd(n - 1) }
    }
}

function odd(n) {
    if (n == 0) {
        return function() { return false };
    } else {
        return function() { return even(n - 1) };
    }
}

function trampoline(f) {
    while(typeof f == "function") {
        f = f();
    }
    return f;
}

console.log(trampoline(function() { return even(10000000) } )) ;

phantom.exit();