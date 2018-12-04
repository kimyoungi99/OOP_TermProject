#pragma once

[event_source(native)]
class GameEndSource {
public:
	__event void GameEndEvent(int gamenumber);
	static GameEndSource *endSource;
};

//GameEndSource* GameEndSource::endSource = NULL;