



with open("./inputs") as file:
    whole_file = file.readlines()

#Writing to the left
with open("./left", 'w') as left:  
    for i in whole_file:
        p = i.split("  ")[0]
        left.write(p + '\n')  

# writing to the right
with open("./right", 'w') as right:  
    for i in whole_file:
        p = i.split("  ")[1]
        right.write(p + '\n')  
