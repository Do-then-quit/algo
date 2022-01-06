//
//  main.swift
//  BJ_1463
//
//  Created by LeeMinkyo on 2020/12/22.
//

import Foundation

let x = Int(readLine()!)!

var arr = [Int](repeating: 0, count: x + 1)
arr[0] = -1
arr[1] = 0
for i in 1...x{
    let minus = arr[i-1] + 1
    var half = Int.max
    var third = Int.max
    if i % 2 == 0 {
        half = arr[i / 2] + 1
    }
    if i % 3 == 0 {
        third = arr[i / 3] + 1
    }
    arr[i] = min(minus, half, third)
}
print(arr[x])
