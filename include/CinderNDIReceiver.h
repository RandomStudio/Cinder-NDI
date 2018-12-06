#pragma once

#include <memory>
#include <windows.h>
#include <Processing.NDI.Lib.h>
#include "cinder/gl/Texture.h"

class CinderNDIReceiver{
	public:
		CinderNDIReceiver();
		~CinderNDIReceiver();

		void setup(std::string streamName);

		void update();
		std::pair<std::string, long long> getMetadata();
		std::pair<ci::gl::Texture2dRef, long long> getVideoTexture();
	private:
		void initConnection(std::string streamName);
	private:
		bool mNdiInitialized = false;
		bool mReadyToReceive = false;
		std::pair<ci::gl::Texture2dRef, long long> mVideoTexture;

		std::pair<std::string, long long> mMetadata;
		NDIlib_recv_instance_t mNdiReceiver;
		NDIlib_find_instance_t mNdiFinder;
		const NDIlib_source_t* mNdiSources = nullptr; // Owned by NDI.

};
