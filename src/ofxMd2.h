/*
 *  ofxMd2.h
 *
 *  Created by Patricio González Vivo on 24/12/10.
 *  Copyright 2010 PatricioGonzalezVivo.com. All rights reserved.
 *
 */


#pragma once

#define NUMVERTEXNORMALS		162		// number of precalculated normals
#define SHADEDOT_QUANT			16		// precalculated normal vectors
#define MD2_IDENT				(('2'<<24) + ('P'<<16) + ('D'<<8) + 'I') // magic number "IDP2" or 844121161
#define	MD2_VERSION				8		// model version
#define MAX_MD2_VERTS			8048	// maximum number of vertices for a MD2 model

#include "ofMain.h"
#include "md2.h"
#include "texture.h"

#include	<fstream>
#include	<vector>

class ofxMd2{
public:
	// constructor/destructor
	ofxMd2( void );
	~ofxMd2( void );
	
	// functions
	void	loadModel(string _MD2file, string _TGAfile, float _size, float _fps );
	bool	loadModel( const char *filename );
	bool	loadSkin( const char *filename );
	
	void	draw(){drawModel( (glutGet( GLUT_ELAPSED_TIME ) / 1000.0));};
	void	drawModel( float time );
	void	drawFrame( int frame );
	
	void	setRotation(float _angle, float _x, float _y, float _z);	// Calibrating the model in order to render it in the right position.
	
	void	setAnim( int type );
	void	scaleModel( float s ) { m_scale = s; }
	
private:
	void	animate( float time );
	void	processLighting( void );
	void	interpolate( vec3_t *vertlist );
	void	renderFrame( void );
	
public:
	// member variables
	static vec3_t	anorms[ NUMVERTEXNORMALS ];
	static float	anorms_dots[ SHADEDOT_QUANT ][256];
	
	static anim_t	animlist[21];		// animation list
	
	int				num_frames;			// number of frames
	float			g_angle;
	int				num_xyz;			// number of vertices
	
private:
	vector<glRot>	rotations;			// Rotations necesary for rendering in the right angle.
	
	int				num_glcmds;			// number of opengl commands
	
	vec3_t			*m_vertices;		// vertex array
	int				*m_glcmds;			// opengl command array
	int				*m_lightnormals;	// normal index array
	
	unsigned int	m_texid;			// texture id
	animState_t		m_anim;				// animation
	float			m_scale;			// scale value
};