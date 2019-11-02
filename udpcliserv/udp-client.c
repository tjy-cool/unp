#include	"unp.h"

void dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen);

int main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: udpcli <IPaddress>");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	dg_cli(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));

	exit(0);
}

void dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    int                n;
    char            sendline[MAXLINE], recvline[MAXLINE + 1];
    socklen_t        len;
    struct sockaddr    *preply_addr;

    preply_addr = Malloc(servlen);

    printf(">>> ");
    fflush(stdout);
    while (Fgets(sendline, MAXLINE, fp) != NULL) {

        // 往服务器发送数据
        Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

        len = servlen;
        n = Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
        // 不接收非指定服务器的数据
        if (len != servlen || memcmp(pservaddr, preply_addr, len) != 0) {
            printf("reply from %s (ignored)\n",
                    Sock_ntop(preply_addr, len));
            continue;
        }

        // 将回射结果打印给用户
        recvline[n] = 0;    /* null terminate */
	    printf("Recv: %s\n", recvline);
        
	    printf(">>> ");
        fflush(stdout);

        //Fputs(recvline, stdout);
    }
}
