//#1
let rec sumEven list =
    match list with
    | [] -> 0
    | hd::tl -> if hd % 2 = 0 then hd + sumEven tl else sumEven tl


sumEven [1; 2; 1; 2; 1; 2];;
 sumEven [1..10];;
sumEven [1; 3; 5; 7; 9];;
  
//#2
//let rec isValidTable tuplelist list




let x = [("Eric", "Mark"); ("Anna", "Maya"); ("Beth", "Hope")]
//isValidTable x ["Eric"; "Anna"; "Beth"];;
     