struct arguments {
    char *message;
    int sock_descriptor;
    uint32_t *length;
};

void* write_back_to_client(void *args) {
    struct arguments* input_args = (struct arguments*) args;
    printf("message is %s\n",input_args->message);
    write_string_to_socket((input_args->sock_descriptor),(input_args->message),*(input_args->length));
    return((void *)0);
}

void * process_client_connection(void * ptr)
{
    connection_t * conn;

    if (!ptr) pthread_exit(0); 
    conn = (connection_t *)ptr;

    printf("Connection received\n");

    int terminate_client = 0;
    do
    {
        /* read length of message */
        char *message = NULL;
        uint32_t message_length = 0;

        /* read message */
        read_string_from_socket(conn->sock, &message, &message_length);
        
        printf("Received = %s\n", message);
        arguments input;
        input.message = message;
        input.length = &message_length;
        input.sock_descriptor = conn->sock;
        
         /* Your logic goes here */
        //pthread_t send_message;
        //pthread_create(&send_message,NULL,write_back_to_client,(void*)&input );
        write(conn->sock,"message",18);
        /* End of operation on this clinet */
        if (strcmp(message, "END") == 0)
            terminate_client = 1;
        
        free(message);

    } while(!terminate_client);

    /* close socket and clean up */
    printf("Closing client on socket %d\n", conn->sock);
    close(conn->sock);
    free(conn);
    pthread_exit(0);
}