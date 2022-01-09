#pragma once

#include <Serialization/Serialization.hpp>
#include <Types.hpp>

#include <memory>

namespace Bousk
{
	namespace Serialization
	{
		class Deserializer;
		class Serializer;
	}

	namespace Network
	{
		namespace Session
		{
			class Message : public Bousk::Serialization::Serializable
			{
			protected:
				enum class Type : uint8
				{
					PlayerJoined,
					PlayerLeft,
					
					Count,
					Last = Count-1,
				};

			protected:
				Message(Type type)
					: mType(type)
				{}

			public:
				~Message() override = default;

				inline Type type() const { return mType; }

				bool write(Bousk::Serialization::Serializer&) const override;
				bool read(Bousk::Serialization::Deserializer&) override;

			private:
				Type mType;
			};

			namespace Messages
			{
				class PlayerJoined : public Message
				{
					;
				};
				class PlayerLeft : public Message
				{
					;
				};
			}
		}
	}
}