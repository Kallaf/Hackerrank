<?php

class DoublyLinkedListNode {
    public $data;
    public $next;
    public $prev;

    public function __construct($node_data)
    {
        $this->data = $node_data;
        $this->next = null;
        $this->prev = null;
    }
}

class DoublyLinkedList {
    public $head;
    public $tail;

    public function __construct()
    {
        $this->head = null;
        $this->tail = null;
    }

    public function insertNode($node_data)
    {
        $node = new DoublyLinkedListNode($node_data);

        if (is_null($this->head)) {
            $this->head = $node;
        } else {
            $this->tail->next = $node;
            $node->prev = $this->tail;
        }

        $this->tail = $node;
    }
}

function printDoublyLinkedList($node, $sep, $fptr)
{
    while (!is_null($node)) {
        fwrite($fptr, $node->data);


        $node = $node->next;

        if (!is_null($node)) {
            fwrite($fptr, $sep);
        }
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode next;
 *     DoublyLinkedListNode prev;
 * }
 *
 */
function sortedInsert($llist, $data) {
    $node = new DoublyLinkedListNode($data);
    if($llist->data >= $data)
    {
        $node->prev = $llist->prev;
        $node->next = $llist;
        $llist->prev = $node;
        $llist = $node;
    }
    else{
        $temp = $llist;
        while($temp->next!=null && $temp->next->data < $data)
            $temp = $temp->next;
        $node->prev = $temp;
        $node->next = $temp->next;
        $temp->next = $node;
        if($temp->next!=null)
            $temp->next->prev = $node;
            
    }
    return $llist;
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");
