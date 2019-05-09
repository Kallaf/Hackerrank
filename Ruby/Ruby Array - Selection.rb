def select_arr(arr)
    return arr.select {|a| a % 2 == 1}
end

def reject_arr(arr)
    return arr.reject {|a| a % 3 == 0}
end

def delete_arr(arr)
    arr.delete_if {|a| a < 0}
end

def keep_arr(arr)
    arr.keep_if {|a| a >= 0}
end
