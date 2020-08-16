
def main_function():
    rotations = int(input())
    outputs = []
    for _ in range(rotations):
        input_1 = input()
        input_1 = input_1.split()
        n,k = int(input_1[0]),int(input_1[1])
        input_1 = input()
        input_1 = input_1.split()
        number_array = []
        
        negative_val = False

        for val in input_1:
            number_array.append(int(val))
            if int(val)<0:
                negative_val = True

        if not negative_val:
            outputs.append(sum(number_array)*k)
        else:
            new_number_array = number_array*2
            temp = []
            total_sum = 0
            for val in new_number_array:
                if val < 0:
                    temp.append(total_sum)
                    total_sum = 0
                else:
                    total_sum += val
            outputs.append(max(temp))
    return outputs

if __name__=='__main__':
    output = main_function()
    for i in output:
        print(i)
