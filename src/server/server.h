/*
 * server.h
 *
 *  Created on: 2023Äê5ÔÂ14ÈÕ
 *      Author: Liyangchuan
 */

#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

uint8_t ServerInit(const uint8_t *addr, uint16_t port, uint8_t useTCP);
uint8_t ServerShutdown();
uint8_t ServerStatus();

#endif /* SERVER_SERVER_H_ */
