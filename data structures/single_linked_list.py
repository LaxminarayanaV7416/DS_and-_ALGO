

class Node(object):
    """
    This is a simple Node class which will accept the data(int) and will hold the reference to
    next node .
    """
    def __init__(self,data):
        self.data = data
        self.next = None
        
    def __repr__(self):
        return str(self.data)


class LinkedList(object):
    """
    This is a simple LinkedList class which we can initialize and append data at the end
    of the linked list. even in this class we have provided the power to print the list
    and even slice the list using repr and getitem special methods.
    """
    def __init__(self):
        self.head = None
        
    def __getitem__(self,index):
        output_node = self.head
        for i in range(index):
            output_node = output_node.next
        return output_node
    
    def __repr__(self):
        iter_node = self.head
        out = []
        while iter_node.next != None:
            out.append(iter_node.data)
            iter_node = iter_node.next
        out.append(iter_node.data)
        return f"{out}"
    
    def append(self,data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
        else:
            iter_node = self.head
            while iter_node.next != None:
                iter_node = iter_node.next
            iter_node.next = new_node

    def insert(self,data,position):
        iter_node = self.head
        for _ in range(position-1):
            iter_node = iter_node.next
        new_node = Node(data)
        new_node.next = iter_node.next
        iter_node.next=new_node
        while iter_node.next!=None:
            iter_node = iter_node.next


    def remove(self,data):
        iter_node = self.head
        while iter_node.data != data:
            previous_node = iter_node
            iter_node = iter_node.next            
        previous_node.next = iter_node.next

    def reverse(self):
        current_node = self.head
        previous_node = None
        while (current_node is not None):
            next_node = current_node.next
            current_node.next = previous_node
            previous_node = current_node
            current_node = next_node    
        self.head = previous_node
            

    def print_middle_value(self):
        mid = self.head
        iter_node = self.head
        count =0
        while iter_node.next!= None:
            count+=1
            iter_node = iter_node.next
            if count%2==1:
                mid = mid.next
        print(mid)

if __name__ == '__main__':
    x = LinkedList()
    x.append(1)
    x.append(2)
    x.append(3)
    x.append(4)
    x.append(5)
    x.insert(12,3)
    x.insert(300,2)
    # x.remove(12)
    print(x)
    x.reverse()
    print(x)
    x.print_middle_value()
    