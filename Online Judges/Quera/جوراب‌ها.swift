/*
 * https://quera.org/problemset/52550/
 * Author: https://github.com/smh997/
 */
var list : [Int] = []
var arr: [[Int]] = [] 
var res: [[Int]] = []

var line = readLine()!
let n  = Int(line) ?? 0
line = readLine()!
let values = line.split(separator: " ");
for i in 0...100{
    list = []
    for j in stride(from: 0, to: n, by: 1){
        if Int(values[j]) == i{
            list.append(j)
        }
    }
    arr.append(list)
}
for i in 1...100{
    if arr[i].count > 1{
        for j in 0...(arr[i].count / 2) - 1 {
            list = [arr[i][2*j]+1, arr[i][2 * j + 1] + 1]
            res.append(list)
        }
    }
}
res.sort { ($0[0]) < ($1[0]) }
print(res.count)
for items in res{
    print("\(items[0]) \(items[1])")
}
