/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_shit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 01:08:52 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/25 01:38:30 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

 
// Create a new node holding 'value'
Node *create_node(int value) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Add a node at the end of the list
void append(Node **head, int value) {
    Node *new_node = create_node(value);

    if (*head == NULL) {          // empty list
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

int main(void) {
    Node *head = NULL;   // empty list

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    print_list(head);    // 10 -> 20 -> 30 -> NULL

    free_list(head);
    return 0;
}
