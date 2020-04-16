//Shaun Lee
//CPSC 3400
//All of the code you turn in must have been written by you without immediate reference to another solution to the problem you are solving.

let maxCubeVolume   l = 
  let rec helper(l,m) =
    match l with
    | [] -> m
    | (x::xs) -> 
        let  a,b,c = x
        let q = 1.0*(a*b*c)
        helper(xs, if ( q > m) then q else m)
  helper (l,0.0)

let findMatches letter list = 
  let rec helper letter list fList =
    match list with 
    | [] -> fList
    | (hd::tl) ->
      let l,n = hd
      if letter = l then helper letter tl (n::fList) else helper letter tl fList
  match list with
  | [] -> []
  | _ -> helper letter list []


// Tree definition for problem 3
type BST =
    | Empty
    | TreeNode of int * BST * BST

let rec insert value tree =
  match tree with
  | Empty -> TreeNode(value,Empty,Empty)
  | TreeNode(v,l,r) when value < v ->
    let left = insert value l
    TreeNode(v,left,r)
  |TreeNode(v,l,r) when value > v ->
    let right = insert value r
    TreeNode((v,l,right))
  | _ ->
    tree

let rec contains value tree =
   match tree with
   | Empty -> false
   | TreeNode(v,l,r) ->
    if value < v then contains value l
    elif value > v then contains value r
    else true

let rec count func tree =
  match tree with
  | Empty -> 0
  | TreeNode(v,l,r) -> 
    if(func v) then 1 + count func l + count func r
    else count func l + count func r

let rec evenCount tree =
  match tree with
  |Empty -> 0
  |TreeNode(v,l,r) -> 
    if v % 2 = 0 then 1 + evenCount l + evenCount r 
    else evenCount l + evenCount r
