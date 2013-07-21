function double (matrix)
    for i = 1, #matrix do
        local array = matrix[i]
        for j = 1, #array do
            array[j] = array[j] * 2
        end
    end

    return matrix;
end
