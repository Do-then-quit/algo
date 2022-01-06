//
//  main.swift
//  BJ_2798
//
//  Created by LeeMinkyo on 2020/12/23.
//

import Foundation

let NM = readLine()!.split(separator: " ").map(){Int($0)!}
var N = NM[0]
var M = NM[1]
var sum = 0
let card = readLine()!.split(separator: " ").map(){Int($0)!}
for i in 0...N-3{
    for j in i+1...N-2{
        for k in j+1...N-1{
            let temp = card[i] + card[j] + card[k]
            if temp <= M && sum < temp {
                sum = temp
            }
        }
    }
}
print(sum)

