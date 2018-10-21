/**
 * @file
 * co.parabox.event.drop node implementation.
 *
 */

#include "node.h"
#include "VuoGlContext.h"
#include <OpenGL/CGLMacro.h>
#include <stdio.h>

VuoModuleMetadata({
					 "title" : "Decimate Events",
					 "keywords" : [ "the mic", "restrict", "bounce", "flow", "siphon", "limit" ],
					 "version" : "1.0.0",
					 "description": "Passes one event for every X number of events received.",
					 "node" : {
						  "exampleCompositions" : [ "" ]
					 }
				 });

VuoInteger * nodeInstanceInit(
	VuoInputData(VuoInteger) samplesPerEvent
	)
{
	VuoInteger* count = (VuoInteger*)malloc(sizeof(VuoInteger));
	VuoRegister(count, free);

	*count = 0;

	return count;
}

void nodeInstanceEvent
(
		VuoInstanceData(VuoInteger*) count,
		VuoInputData(VuoGenericType1, {"eventBlocking":"door", "hasPortAction":true}) value,
		VuoInputData(VuoInteger, {"default":1, "suggestedMin":1, "suggestedMax":32}) samplesPerEvent,
		VuoOutputData(VuoGenericType1) output
)
{
	(**count)++;

	if( (**count) > samplesPerEvent )
	{
		*output = value;
		(**count) = 0;
	}
}

void nodeInstanceFini(VuoInstanceData(VuoInteger*) instance)
{
}
