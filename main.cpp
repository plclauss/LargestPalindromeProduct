#include <iostream>
#include <cstddef>

//struct for linked list
//struct Node {
//    int value;
//    struct Node *next;
//};
//
//int reverseNumber(int product) {
//    int magnitude = 1, temp = product, answer = 0;
//    while (product != 0) {
//        magnitude *= 10; //increase magnitude by 10 for size of number
//        product /= 10;
//    }
//    magnitude /= 10; //account for extra magnitude
//
//    product = temp;
//    while (product != 0) {
//        answer += ((product % 10) * magnitude); //answer will be reversed number
//        product /= 10;
//        magnitude /= 10;
//    }
//    return answer;
//}
//
//Node* createLinkedList(int product) {
//    if ((product / 10) != 0) {
//        product /= 10;
//
//        Node* next;
//        next = (Node*)malloc(sizeof(struct Node));
//
//        next->value = product % 10;
//        next->next = createLinkedList(product); //recursively create list, given reversed number
//
//        return next;
//    }
//    else
//        return nullptr;
//}
//
//int isPalindrome(Node* head, int product) {
//    //check if number is palindrome
//    while (head->next != nullptr) {
//        if ((product % 10) != head->value)
//            return -1;
//        else {
//            product /= 10;
//            head = head->next;
//        }
//    }
//    return 1;
//}
//
//void freeList(Node* head) {
//    //recursively free list
//    if (head->next == nullptr) {
//        free(head);
//        return;
//    }
//    else
//        freeList(head->next);
//}
//
//int findProduct() {
//    int highest = 0; //current highest palindrome
//    for (int i = 999; i >= 100; i--) {
//        for (int j = 999; j >= 100; j--) {
//            int reversed = reverseNumber(i*j); //reverse the product
//
//            Node *head;
//            head = (Node*)malloc(sizeof(struct Node)); //create new head of linked list
//
//            head->value = (reversed) % 10;
//            head->next = createLinkedList(reversed); //create rest of the list
//
//            int result = isPalindrome(head, i * j); //check if number is palindrome
//            if (result == 1 && (i * j) > highest)
//                highest = i * j; //set highest palindrome
//
//            freeList(head); //free allocated memory
//        }
//    }
//    return highest;
//}

int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = 10*reversed + n % 10;
        n /= 10;
    }
    return reversed;
}

int isPalindrome(int product) {
    return (product == reverseNumber(product));
}

int main() {
    //std::cout << findProduct() << std::endl;

    int largest = 0, a = 0, b = 0, decB = 0;
    a = 999;
    while (a >= 100) {
        if ((a % 11) == 0) {
            b = 999;
            decB = 1;
        }
        else {
            b = 990;
            decB = 11;
        }
        while (b >= a) {
            if ((a * b) <= largest)
                break;
            if (isPalindrome(a*b))
                largest = a * b;
            b -= decB;
        }
        a--;
    }
    std::cout << largest << std::endl;

    return 0;
}