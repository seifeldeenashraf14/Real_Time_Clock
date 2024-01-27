/************************************************/
/* Description : SevenSegment config header File*/
/* Author      : ahmed saeed                    */
/* Version     : 0.1V                           */
/* Date        : 10:19:33  05 Aug 2023          */
/* History     : 0.1V Initial Creation          */
/************************************************/

#include "StdTypes.h"
#include "DIO_interface.h"
#include "SEVENSEGMENT_cfg.h"
#include "SEVENSEGMENT_priv.h"



tstrSevenSegConfig SEV_ConfigSet[SEV_MAX_NUM]=
{
		{
				{         /* a*/          /* b*/          /* c*/
						PINA0,           PINA1,           PINA2,
						  /* d*/         /*e*/            /* f*/
						PINA3,           PINA4,           PINA5,
						/* g*/
						PINA6
				},
				/* common*/
				PINA7,

				COMMON_ANODE  //20
		},


		{
						{         /* a*/          /* b*/          /* c*/
								PINA0,PINA1,PINA2,
								  /* d*/         /*e*/            /* f*/
								PINA3,PINA4,PINA5,
								/* g*/
								PINA6
						},
						/* common*/
						   PINB0,

						   COMMON_ANODE  //20
			},
			{
									{         /* a*/          /* b*/          /* c*/
											PINA0,PINA1,PINA2,
											  /* d*/         /*e*/            /* f*/
											PINA3,PINA4,PINA5,
											/* g*/
											PINA6
									},
									/* common*/
									   PINB1,

									   COMMON_ANODE  //20
						},
						{
												{         /* a*/          /* b*/          /* c*/
														PINA0,PINA1,PINA2,
														  /* d*/         /*e*/            /* f*/
														PINA3,PINA4,PINA5,
														/* g*/
														PINA6
												},
												/* common*/
												   PINB2,

												   COMMON_ANODE  //20
									},
									{
															{         /* a*/          /* b*/          /* c*/
																	PINA0,PINA1,PINA2,
																	  /* d*/         /*e*/            /* f*/
																	PINA3,PINA4,PINA5,
																	/* g*/
																	PINA6
															},
															/* common*/
															   PINB3,

															   COMMON_ANODE  //20
												},
												{
																		{         /* a*/          /* b*/          /* c*/
																				PINA0,PINA1,PINA2,
																				  /* d*/         /*e*/            /* f*/
																				PINA3,PINA4,PINA5,
																				/* g*/
																				PINA6
																		},
																		/* common*/
																		   PINB4,

																		   COMMON_ANODE  //20
															},

};
