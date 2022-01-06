//
//  main.swift
//  BJ_1259
//
//  Created by LeeMinkyo on 2020/12/24.
//

import Foundation

while true {
    let arr = readLine()!
    if arr == "0" {
        exit(0)
    }
    let arr2 = String(arr.reversed())
    if arr == arr2{
        print("yes")
    }
    else {
        print("no")
    }
}

