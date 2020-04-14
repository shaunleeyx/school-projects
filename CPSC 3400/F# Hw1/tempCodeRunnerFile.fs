let maxCubeVolume list = 
    let rec helper (list,m)= 
        match list with
        | [] -> m
        | hd :: tl -> 
            let (a,b,c) = hd
            let x = (a*b*c)
            helper(tl,if(x > m) then x else m)
    helper (list,one)
