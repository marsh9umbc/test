#include "list.h"
#include "stdlib.h"
#include "stdio.h"
#include "stddef.h"

long create_mbox_421(unsigned long id, int crypt_alg); //creates a new empty mailbox with ID id, if it does not already exist, and returns 0. If the crypt_alg parameter is 0, the mailbox's messages shall be encrypted with the XOR cipher described above. Otherwise, the messages shall be encrypted with the XTEA algorithm.
long remove_mbox_421(unsigned long id); //removes mailbox with ID id, if it is empty, and returns 0. If the mailbox is not empty, this system call shall return an appropriate error and not remove the mailbox.
//long count_mbox_421(void); //returns the number of existing mailboxes.
//long list_mbox_421(unsigned long __user *mbxes, long k); //returns a list of up to k mailbox IDs in the user-space variable mbxes. It returns the number of IDs written successfully to mbxes on success and an appropriate error code on failure.
//long send_msg_421(unsigned long id, unsigned char __user *msg, long n, uint32_t __user *key); //encrypts the message msg (using the correct algorithm), adding it to the already existing mailbox identified. Returns the number of bytes stored (which shall be equal to the message length n) on success, and an appropriate error code on failure. Messages with negative lengths shall be rejected as invalid and cause an appropriate error to be returned, however messages with a length of zero shall be accepted as valid.
//long recv_msg_421(unsigned long id, unsigned char __user *msg, long n, uint32_t __user *key); //copies up to n characters from the next message in the mailbox id to the user-space buffer msg, decrypting with the specified key, and removes the entire message from the mailbox (even if only part of the message is copied out). Returns the number of bytes successfully copied (which shall be the minimum of the length of the message that is stored and n) on success or an appropriate error code on failure.
//long peek_msg_421(unsigned long id, unsigned char __user *msg, long n, uint32_t __user *key); //performs the same operation as recv_msg_421() without removing the message from the mailbox.
//long count_msg_421(unsigned long id); //returns the number of messages in the mailbox id on success or an appropriate error code on failure.
//long len_msg_421(unsigned long id); //returns the length of the next message that would be returned by calling recv_msg_421() with the same id value (that is the number of bytes in the next message in the mailbox). If there are no messages in the mailbox, this shall return an appropriate error value.

//mailbox struct to send/recieve messages
typedef struct mail
{ 
    unsigned char *msg;
    long msgLen;

    // This is used to link components together in their list
    struct list_head list_node;
} mail_t;
//mail struct for holding bits
typedef struct mbox 
{ 
    //mailbox id
    unsigned long id;
    int crypt_alg;

    // This is used to link players together in the players list
    struct list_head list_node;
    //list of mail
    struct list_head list_mail;
} mbox_t;

// This list is not type-safe. e.g It does not accept
// only certain structs
LIST_HEAD(list_mbox);

//creates a new empty mailbox with ID id, if it does not already exist, and returns 0. 
//If the crypt_alg parameter is 0, the mailbox's messages shall be encrypted with the XOR 
//cipher described above. Otherwise, the messages shall be encrypted with the XTEA algorithm.
long create_mbox_421(unsigned long id, int crypt_alg)
{
    //check if exists (iterate through list)
    struct  list_head *pos;
    int counter = 0; 

    list_for_each(pos, &list_mbox) {
        // In here pos will be the list_head item in the corresponding player struct
        mbox_t* p = NULL;

        // Extract get a reference to the mbox_t for this iteration
        p = list_entry(pos, mbox_t, list_node);

        if(p->id == id){
            printf("ERROR:You attempted to create a mailbox that already exists\n");
            return 1;
        }
        counter++;
    }

    //if not create new mbox
    mbox_t *mbox_node = (mbox_t*)malloc(sizeof(mbox_t));
    INIT_LIST_HEAD(&mbox_node->list_mail);

    //encrypt mbox messages using XOR
    if( crypt_alg == 0){
        
    }
    //encrypt mbox messages using XTEA
    else if ( crypt_alg == 1){

    }
    else{
        printf("ERROR:Invalid crypt_alg value\n");
        return 1;
    }
}
//removes mailbox with ID id, if it is empty, and returns 0. If the mailbox is not empty, this
//system call shall return an appropriate error and not remove the mailbox.
long remove_mbox_421(unsigned long id)
{

}

int main() {
    //initialize a mailbox.
    //encrypt mail.

    return 0;
}
