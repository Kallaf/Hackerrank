def end_arr_add(arr, element)
    arr.push(element)
    return arr
end

def begin_arr_add(arr, element)
    arr.unshift(element)
    return arr
end

def index_arr_add(arr, index, element)
    arr.insert(index,element)
    return arr
end

def index_arr_multiple_add(arr, index)
    arr.insert(index,1,2)
end
