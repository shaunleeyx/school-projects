let sumEven list
    let rec helper list,fList=
        match list with
        | [] -> fList
        | hd::tl -> if hd % 2 = 0 then sumEven (hd::fList) else sumEven tl
    helper list,[]

sumEven [1; 2; 1; 2; 1; 2];;
 sumEven [1..10];;
sumEven [1; 3; 5; 7; 9];;
  
//#2
//let rec isValidTable tuplelist list




let x = [("Eric", "Mark"); ("Anna", "Maya"); ("Beth", "Hope")]
//isValidTable x ["Eric"; "Anna"; "Beth"];;
     