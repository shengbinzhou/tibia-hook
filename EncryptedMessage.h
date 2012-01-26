#ifndef ENCRYPTEDMESSAGE_H_
#define ENCRYPTEDMESSAGE_H_

#include <stdint.h>

#include <QByteArray>

#include "Message.h"

class DecryptedMessage;
class EncryptedMessage: public Message {
	static const int HEADER_POSITION = 0;
	static const int HEADER_LENGTH = 2;
	static const int CHECKSUM_POSITION = HEADER_POSITION + HEADER_LENGTH;
	static const int CHECKSUM_LENGTH = 4;
	static const int DATA_POSITION = CHECKSUM_POSITION + CHECKSUM_LENGTH;

public:
	EncryptedMessage();
	EncryptedMessage(const uint8_t*, uint16_t);

	bool isValid() const;

	uint16_t length() const;
	const uint8_t* data() const;

	static EncryptedMessage encrypt(const DecryptedMessage&, const uint32_t []);

private:
	QByteArray _raw;
	uint16_t _dataLength;
	uint32_t _checksum;
	uint16_t _needsMore;
};

#endif /* ENCRYPTEDMESSAGE_H_ */
