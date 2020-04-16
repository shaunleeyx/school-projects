let eval vars expr = 
    let cList = Seq.toList expr 
    let rec innerEval vars stack expr = 
    match expr with
    | [] -> []
    | hd::tl -> if hd = "-" || hd = "+" || hd = "*" || hd = "/" || hd = "$" then 
innerEval vars [] cList

let matching symbol stack =
    let a = pop stack
     match symbol with
    |"-" ->
    |"+"->
    |"*" ->
    |"/" ->

let pop stack =
    match stack with
    |[] -> ()
    |hd::tl -> hd




let testEval = eval [("a",5);("b",2);("c",9)] 
let exprList = ["ab-";"ba-"]
let resultList = List.map testEval exprList



    // let cList expr = 
    //     match expr with
    //     |[] -> expr
    //     |hd::tl -> hd :: cList tl