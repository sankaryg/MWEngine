/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2014 Igor Zinken - http://www.igorski.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "processingchain.h"
#include "global.h"
#include <math.h>
#include "utils.h"

// constructor

ProcessingChain::ProcessingChain()
{

}

ProcessingChain::~ProcessingChain()
{
    _activeProcessors.clear();
    _activeBusProcessors.clear();
}

/* public methods */

void ProcessingChain::addProcessor( BaseProcessor* aProcessor )
{
    _activeProcessors.push_back( aProcessor );
}

void ProcessingChain::removeProcessor( BaseProcessor* aProcessor )
{
    for ( int i = 0; i < _activeProcessors.size(); i++ )
    {
        if ( _activeProcessors.at( i ) == aProcessor )
        {
            _activeProcessors.erase( _activeProcessors.begin() + i );
            break;
        }
    }
}
void ProcessingChain::addBusProcessor( BaseBusProcessor* aBusProcessor )
{
    _activeBusProcessors.push_back( aBusProcessor );
}

void ProcessingChain::removeBusProcessor( BaseBusProcessor* aBusProcessor )
{
    for ( int i = 0; i < _activeBusProcessors.size(); i++ )
    {
        if ( _activeBusProcessors.at( i ) == aBusProcessor )
        {
            _activeBusProcessors.erase( _activeBusProcessors.begin() + i );
            break;
        }
    }
}

void ProcessingChain::reset()
{
    _activeProcessors.clear();
    _activeBusProcessors.clear();
}

std::vector<BaseProcessor*> ProcessingChain::getActiveProcessors()
{
    return _activeProcessors;
}

std::vector<BaseBusProcessor*> ProcessingChain::getActiveBusProcessors()
{
    return _activeBusProcessors;
}
