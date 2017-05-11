//(c) 2016 by Authors
//This file is a part of ABruijn program.
//Released under the BSD license (see LICENSE file)

#pragma once

#include "../sequence/overlap.h"
#include "../sequence/sequence_container.h"
#include <unordered_map>

class ChimeraDetector
{
public:
	ChimeraDetector(const SequenceContainer& readContainer,
					OverlapContainer& ovlpContainer):
		_seqContainer(readContainer),
		_ovlpContainer(ovlpContainer), 
		_coverage(0)
	{}

	void estimateGlobalCoverage();
	bool isChimeric(FastaRecord::Id readId);
	//int getCoverage() const {return _coverage;}

private:
	std::vector<int32_t> getReadCoverage(FastaRecord::Id readId);
	bool testReadByCoverage(FastaRecord::Id readId);

	const SequenceContainer& _seqContainer;
	OverlapContainer& _ovlpContainer;

	std::unordered_map<FastaRecord::Id, bool> _chimeras;
	int _coverage;
};
