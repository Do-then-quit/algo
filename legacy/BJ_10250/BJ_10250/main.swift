//
//  main.swift
//  BJ_10250
//
//  Created by LeeMinkyo on 2020/12/23.
//

import Foundation

let cases = Int(readLine()!)!
for i in 1...cases {
    let input = readLine()!.split(separator: " ").map(){ Int($0)! }
    let H = input[0]
    let W = input[1]
    let customer = input[2]
    var X = customer / H + 1
    var Y = customer % H
    if Y == 0 {
        Y = H
        X = X - 1
    }
    if X < 10
    {
        print("\(Y)0\(X)")
    }
    else
    {
        print("\(Y)\(X)")
    }
    
}

