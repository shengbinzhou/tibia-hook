#ifndef SCRIPTHANDLER_H_
#define SCRIPTHANDLER_H_

#include <QObject>
#include <QFile>
#include <QHash>
#include <QStringList>
#include <QScriptEngine>
#include <QScriptContext>
#include <QScriptEngineAgent>

#include "Handler.h"
#include "Hook.h"
#include "EncryptedMessage.h"
#include "Module.h"

class ScriptHandler: public Handler {
	Q_OBJECT

public:
	ScriptHandler(Hook*);

	Hook* hook();
	QScriptEngine* engine();

	bool install(Module*);

	void reload();

	void receiveFromClient(const EncryptedMessage*);
	void receiveFromServer(const EncryptedMessage*);

private:
	bool receiveFromClientInternal(const EncryptedMessage*);

	Hook* hook_;

	QScriptEngine engine_;
	QScriptString receiveFromClientHandle_;
	QScriptString receiveFromServerHandle_;

	QHash<QString, Module*> modules_;
};

#endif /* SCRIPTHANDLER_H_ */
