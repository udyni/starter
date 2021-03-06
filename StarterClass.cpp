/*----- PROTECTED REGION ID(StarterClass.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        StarterClass.cpp
//
// description : C++ source for the StarterClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the �name� once per process.
//
// project :     Starter for Tango Administration.
//
// $Author$
//
// Copyright (C) :      2004,2005,2006,2007,2008,2009,2010,2011,2012,2013,2014,2015
//						European Synchrotron Radiation Facility
//                      BP 220, Grenoble 38043
//                      FRANCE
//
// This file is part of Tango.
//
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
//
// $Revision$
// $Date$
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <tango.h>
#include <Starter.h>
#include <StarterClass.h>

/*----- PROTECTED REGION END -----*/	//	StarterClass.cpp

//-------------------------------------------------------------------
/**
 *	Create StarterClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Starter_class(const char *name) {
		return Starter_ns::StarterClass::init(name);
	}
}

namespace Starter_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
StarterClass *StarterClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		StarterClass::StarterClass(string &s)
 * description : 	constructor for the StarterClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
StarterClass::StarterClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering StarterClass constructor" << endl;
	set_default_property();
	get_class_property();
	write_class_property();

	/*----- PROTECTED REGION ID(StarterClass::constructor) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	StarterClass::constructor

	cout2 << "Leaving StarterClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		StarterClass::~StarterClass()
 * description : 	destructor for the StarterClass
 */
//--------------------------------------------------------
StarterClass::~StarterClass()
{
	/*----- PROTECTED REGION ID(StarterClass::destructor) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	StarterClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		StarterClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
StarterClass *StarterClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new StarterClass(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		StarterClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
StarterClass *StarterClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method : 		DevStartClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevStartClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "DevStartClass::execute(): arrived" << endl;
	Tango::DevString argin;
	extract(in_any, argin);
	((static_cast<Starter *>(device))->dev_start(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		DevStopClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevStopClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "DevStopClass::execute(): arrived" << endl;
	Tango::DevString argin;
	extract(in_any, argin);
	((static_cast<Starter *>(device))->dev_stop(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		DevStartAllClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevStartAllClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "DevStartAllClass::execute(): arrived" << endl;
	Tango::DevShort argin;
	extract(in_any, argin);
	((static_cast<Starter *>(device))->dev_start_all(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		DevStopAllClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevStopAllClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "DevStopAllClass::execute(): arrived" << endl;
	Tango::DevShort argin;
	extract(in_any, argin);
	((static_cast<Starter *>(device))->dev_stop_all(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		DevGetRunningServersClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevGetRunningServersClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "DevGetRunningServersClass::execute(): arrived" << endl;
	Tango::DevBoolean argin;
	extract(in_any, argin);
	return insert((static_cast<Starter *>(device))->dev_get_running_servers(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevGetStopServersClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevGetStopServersClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "DevGetStopServersClass::execute(): arrived" << endl;
	Tango::DevBoolean argin;
	extract(in_any, argin);
	return insert((static_cast<Starter *>(device))->dev_get_stop_servers(argin));
}

//--------------------------------------------------------
/**
 * method : 		DevReadLogClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *DevReadLogClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "DevReadLogClass::execute(): arrived" << endl;
	Tango::DevString argin;
	extract(in_any, argin);
	return insert((static_cast<Starter *>(device))->dev_read_log(argin));
}

//--------------------------------------------------------
/**
 * method : 		HardKillServerClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *HardKillServerClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "HardKillServerClass::execute(): arrived" << endl;
	Tango::DevString argin;
	extract(in_any, argin);
	((static_cast<Starter *>(device))->hard_kill_server(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		ResetStatisticsClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *ResetStatisticsClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "ResetStatisticsClass::execute(): arrived" << endl;
	((static_cast<Starter *>(device))->reset_statistics());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		UpdateServersInfoClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *UpdateServersInfoClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "UpdateServersInfoClass::execute(): arrived" << endl;
	((static_cast<Starter *>(device))->update_servers_info());
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : StarterClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum StarterClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : StarterClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum StarterClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : StarterClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum StarterClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : StarterClass::get_class_property()
 *	Description : Read database to initialize class property data members.
 */
//--------------------------------------------------------
void StarterClass::get_class_property()
{
	/*----- PROTECTED REGION ID(StarterClass::get_class_property_before) ENABLED START -----*/

	//	Initialize class property data members
	readInfoDbPeriod  = 4;
	nbStartupLevels   = 5;
	logFileHome = LOG_HOME;

	/*----- PROTECTED REGION END -----*/	//	StarterClass::get_class_property_before
	//	Read class properties from database.
	cl_prop.push_back(Tango::DbDatum("AutoRestartDuration"));
	cl_prop.push_back(Tango::DbDatum("LogFileHome"));
	cl_prop.push_back(Tango::DbDatum("NbStartupLevels"));
	cl_prop.push_back(Tango::DbDatum("ReadInfoDbPeriod"));
	cl_prop.push_back(Tango::DbDatum("ServerStartupTimeout"));
	cl_prop.push_back(Tango::DbDatum("StartServersAtStartup"));
	cl_prop.push_back(Tango::DbDatum("MovingMaxDuration"));
	
	//	Call database and extract values
	if (Tango::Util::instance()->_UseDb==true)
		get_db_class()->get_property(cl_prop);
	Tango::DbDatum	def_prop;
	int	i = -1;

	//	Try to extract AutoRestartDuration value
	if (cl_prop[++i].is_empty()==false)	cl_prop[i]  >>  autoRestartDuration;
	else
	{
		//	Check default value for AutoRestartDuration
		def_prop = get_default_class_property(cl_prop[i].name);
		if (def_prop.is_empty()==false)
		{
			def_prop    >>  autoRestartDuration;
			cl_prop[i]  <<  autoRestartDuration;
		}
	}
	//	Try to extract LogFileHome value
	if (cl_prop[++i].is_empty()==false)	cl_prop[i]  >>  logFileHome;
	else
	{
		//	Check default value for LogFileHome
		def_prop = get_default_class_property(cl_prop[i].name);
		if (def_prop.is_empty()==false)
		{
			def_prop    >>  logFileHome;
			cl_prop[i]  <<  logFileHome;
		}
	}
	//	Try to extract NbStartupLevels value
	if (cl_prop[++i].is_empty()==false)	cl_prop[i]  >>  nbStartupLevels;
	else
	{
		//	Check default value for NbStartupLevels
		def_prop = get_default_class_property(cl_prop[i].name);
		if (def_prop.is_empty()==false)
		{
			def_prop    >>  nbStartupLevels;
			cl_prop[i]  <<  nbStartupLevels;
		}
	}
	//	Try to extract ReadInfoDbPeriod value
	if (cl_prop[++i].is_empty()==false)	cl_prop[i]  >>  readInfoDbPeriod;
	else
	{
		//	Check default value for ReadInfoDbPeriod
		def_prop = get_default_class_property(cl_prop[i].name);
		if (def_prop.is_empty()==false)
		{
			def_prop    >>  readInfoDbPeriod;
			cl_prop[i]  <<  readInfoDbPeriod;
		}
	}
	//	Try to extract ServerStartupTimeout value
	if (cl_prop[++i].is_empty()==false)	cl_prop[i]  >>  serverStartupTimeout;
	else
	{
		//	Check default value for ServerStartupTimeout
		def_prop = get_default_class_property(cl_prop[i].name);
		if (def_prop.is_empty()==false)
		{
			def_prop    >>  serverStartupTimeout;
			cl_prop[i]  <<  serverStartupTimeout;
		}
	}
	//	Try to extract StartServersAtStartup value
	if (cl_prop[++i].is_empty()==false)	cl_prop[i]  >>  startServersAtStartup;
	else
	{
		//	Check default value for StartServersAtStartup
		def_prop = get_default_class_property(cl_prop[i].name);
		if (def_prop.is_empty()==false)
		{
			def_prop    >>  startServersAtStartup;
			cl_prop[i]  <<  startServersAtStartup;
		}
	}
	//	Try to extract MovingMaxDuration value
	if (cl_prop[++i].is_empty()==false)	cl_prop[i]  >>  movingMaxDuration;
	else
	{
		//	Check default value for MovingMaxDuration
		def_prop = get_default_class_property(cl_prop[i].name);
		if (def_prop.is_empty()==false)
		{
			def_prop    >>  movingMaxDuration;
			cl_prop[i]  <<  movingMaxDuration;
		}
	}
	/*----- PROTECTED REGION ID(StarterClass::get_class_property_after) ENABLED START -----*/

	//	Check class property data members init
	cout2 << "readInfoDbPeriod  = " << readInfoDbPeriod << endl;
	cout2 << "nbStartupLevels   = " << nbStartupLevels << endl;
	cout2 << "logFileHome       = " << logFileHome   << endl;

	//	Put the value (depends on OS) in cl_prop to be set as default value for device property..
	for (auto & i : cl_prop)
		if (i.name == "LogFileHome")
			i  <<  logFileHome;

	/*----- PROTECTED REGION END -----*/	//	StarterClass::get_class_property_after

}

//--------------------------------------------------------
/**
 *	Method      : StarterClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void StarterClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties
	prop_name = "AutoRestartDuration";
	prop_desc = "If this property is greater than 0, if a server has been running more than the specified value (in minutes), and has failed, it will be restart automatically.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		cl_def_prop.push_back(data);
		add_wiz_class_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_class_prop(prop_name, prop_desc);
	prop_name = "LogFileHome";
	prop_desc = "The home directory to log servers traces.\nFor Linux the default value is /var/tmp\nFor Win32 it is c:\temp";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		cl_def_prop.push_back(data);
		add_wiz_class_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_class_prop(prop_name, prop_desc);
	prop_name = "NbStartupLevels";
	prop_desc = "Number of startup levels managed by starter.";
	prop_def  = "5";
	vect_data.clear();
	vect_data.push_back("5");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		cl_def_prop.push_back(data);
		add_wiz_class_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_class_prop(prop_name, prop_desc);
	prop_name = "ReadInfoDbPeriod";
	prop_desc = "Period to read database for new info if not fired from Database server.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		cl_def_prop.push_back(data);
		add_wiz_class_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_class_prop(prop_name, prop_desc);
	prop_name = "ServerStartupTimeout";
	prop_desc = "Timeout on device server startup in seconds.";
	prop_def  = "1";
	vect_data.clear();
	vect_data.push_back("1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		cl_def_prop.push_back(data);
		add_wiz_class_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_class_prop(prop_name, prop_desc);
	prop_name = "StartServersAtStartup";
	prop_desc = "Skip starting servers at startup if false. It a way to do not have a big re-start of many servers after a power cut.";
	prop_def  = "true";
	vect_data.clear();
	vect_data.push_back("true");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		cl_def_prop.push_back(data);
		add_wiz_class_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_class_prop(prop_name, prop_desc);
	prop_name = "MovingMaxDuration";
	prop_desc = "If a server is moving during a period more than this value,\nthe Starter will be switched from MOVING to STANDBY";
	prop_def  = "120";
	vect_data.clear();
	vect_data.push_back("120");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		cl_def_prop.push_back(data);
		add_wiz_class_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_class_prop(prop_name, prop_desc);

	//	Set Default device Properties
	prop_name = "AutoRestartDuration";
	prop_desc = "If this property is greater than 0, if a server has been running more than the specified value (in minutes), and has failed, it will be restart automatically.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "InterStartupLevelWait";
	prop_desc = "Time to wait before two startup levels in seconds.";
	prop_def  = "1";
	vect_data.clear();
	vect_data.push_back("1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "KeepLogFiles";
	prop_desc = "Number of log file kept.";
	prop_def  = "3";
	vect_data.clear();
	vect_data.push_back("3");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "LogFileHome";
	prop_desc = "The home directory to log servers traces.\nFor Linux the default value is /var/tmp\nFor Win32 it is c:\temp";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "ServerStartupTimeout";
	prop_desc = "Timeout on device server startup in seconds.";
	prop_def  = "5";
	vect_data.clear();
	vect_data.push_back("5");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "StartDsPath";
	prop_desc = "Path to find executable files\nto start device servers";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "StartServersAtStartup";
	prop_desc = "Skip starting servers at startup if false.";
	prop_def  = "true";
	vect_data.clear();
	vect_data.push_back("true");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "WaitForDriverStartup";
	prop_desc = "The Starter will wait a bit before starting servers, to be sure than the drivers\nare started.This time is in seconds.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "MovingMaxDuration";
	prop_desc = "If a server is moving during a period more than this value,\nthe Starter will be switched from MOVING to STANDBY";
	prop_def  = "120";
	vect_data.clear();
	vect_data.push_back("120");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : StarterClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void StarterClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("Starter for Tango Administration");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("This device server is able to control <b>Tango</b> components (database, device servers, clients...).");
	str_desc.push_back("It is able to start or stop and to report the status of these components.");
	description << str_desc;
	data.push_back(description);

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : StarterClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void StarterClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(StarterClass::device_factory_before) ENABLED START -----*/

	//	Add your own code


	/*----- PROTECTED REGION END -----*/	//	StarterClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new Starter(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		Starter *dev = static_cast<Starter *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(StarterClass::device_factory_after) ENABLED START -----*/

	//	Add your own code


	/*----- PROTECTED REGION END -----*/	//	StarterClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : StarterClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void StarterClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(StarterClass::attribute_factory_before) ENABLED START -----*/

	//	Add your own code

	/*----- PROTECTED REGION END -----*/	//	StarterClass::attribute_factory_before
	//	Attribute : HostState
	HostStateAttrib	*hoststate = new HostStateAttrib();
	Tango::UserDefaultAttrProp	hoststate_prop;
	//	description	not set for HostState
	//	label	not set for HostState
	//	unit	not set for HostState
	//	standard_unit	not set for HostState
	//	display_unit	not set for HostState
	//	format	not set for HostState
	//	max_value	not set for HostState
	//	min_value	not set for HostState
	//	max_alarm	not set for HostState
	//	min_alarm	not set for HostState
	//	max_warning	not set for HostState
	//	min_warning	not set for HostState
	//	delta_t	not set for HostState
	//	delta_val	not set for HostState
	
	hoststate->set_default_properties(hoststate_prop);
	hoststate->set_polling_period(1000);
	hoststate->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(hoststate);

	//	Attribute : RunningServers
	RunningServersAttrib	*runningservers = new RunningServersAttrib();
	Tango::UserDefaultAttrProp	runningservers_prop;
	//	description	not set for RunningServers
	//	label	not set for RunningServers
	//	unit	not set for RunningServers
	//	standard_unit	not set for RunningServers
	//	display_unit	not set for RunningServers
	//	format	not set for RunningServers
	//	max_value	not set for RunningServers
	//	min_value	not set for RunningServers
	//	max_alarm	not set for RunningServers
	//	min_alarm	not set for RunningServers
	//	max_warning	not set for RunningServers
	//	min_warning	not set for RunningServers
	//	delta_t	not set for RunningServers
	//	delta_val	not set for RunningServers
	
	runningservers->set_default_properties(runningservers_prop);
	runningservers->set_polling_period(1000);
	runningservers->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(runningservers);

	//	Attribute : StoppedServers
	StoppedServersAttrib	*stoppedservers = new StoppedServersAttrib();
	Tango::UserDefaultAttrProp	stoppedservers_prop;
	stoppedservers_prop.set_description("Return all the Stopped servers.");
	stoppedservers_prop.set_label("All Stopped Servers");
	//	unit	not set for StoppedServers
	//	standard_unit	not set for StoppedServers
	//	display_unit	not set for StoppedServers
	//	format	not set for StoppedServers
	//	max_value	not set for StoppedServers
	//	min_value	not set for StoppedServers
	//	max_alarm	not set for StoppedServers
	//	min_alarm	not set for StoppedServers
	//	max_warning	not set for StoppedServers
	//	min_warning	not set for StoppedServers
	//	delta_t	not set for StoppedServers
	//	delta_val	not set for StoppedServers
	
	stoppedservers->set_default_properties(stoppedservers_prop);
	stoppedservers->set_polling_period(1000);
	stoppedservers->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(stoppedservers);

	//	Attribute : Servers
	ServersAttrib	*servers = new ServersAttrib();
	Tango::UserDefaultAttrProp	servers_prop;
	servers_prop.set_description("Return all registered servers for this host.\nServer names are followed by:   [states] [controlled] [level] [nb instances]\nIf nb instances >1 a warning will be displayed in Astor");
	servers_prop.set_label("Servers");
	//	unit	not set for Servers
	//	standard_unit	not set for Servers
	//	display_unit	not set for Servers
	//	format	not set for Servers
	//	max_value	not set for Servers
	//	min_value	not set for Servers
	//	max_alarm	not set for Servers
	//	min_alarm	not set for Servers
	//	max_warning	not set for Servers
	//	min_warning	not set for Servers
	//	delta_t	not set for Servers
	//	delta_val	not set for Servers
	
	servers->set_default_properties(servers_prop);
	servers->set_polling_period(1000);
	servers->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(servers);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(StarterClass::attribute_factory_after) ENABLED START -----*/

	//	Add your own code

	/*----- PROTECTED REGION END -----*/	//	StarterClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : StarterClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void StarterClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(StarterClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	StarterClass::pipe_factory_before
	/*----- PROTECTED REGION ID(StarterClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	StarterClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : StarterClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void StarterClass::command_factory()
{
	/*----- PROTECTED REGION ID(StarterClass::command_factory_before) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	StarterClass::command_factory_before

	//	Set polling perod for command State
	Tango::Command	&stateCmd = get_cmd_by_name("State");
	stateCmd.set_polling_period(1000);
	

	//	Command DevStart
	DevStartClass	*pDevStartCmd =
		new DevStartClass("DevStart",
			Tango::DEV_STRING, Tango::DEV_VOID,
			"Server to be started.",
			"",
			Tango::OPERATOR);
	command_list.push_back(pDevStartCmd);

	//	Command DevStop
	DevStopClass	*pDevStopCmd =
		new DevStopClass("DevStop",
			Tango::DEV_STRING, Tango::DEV_VOID,
			"Servero be stopped.",
			"",
			Tango::OPERATOR);
	command_list.push_back(pDevStopCmd);

	//	Command DevStartAll
	DevStartAllClass	*pDevStartAllCmd =
		new DevStartAllClass("DevStartAll",
			Tango::DEV_SHORT, Tango::DEV_VOID,
			"Startup level.",
			"",
			Tango::OPERATOR);
	command_list.push_back(pDevStartAllCmd);

	//	Command DevStopAll
	DevStopAllClass	*pDevStopAllCmd =
		new DevStopAllClass("DevStopAll",
			Tango::DEV_SHORT, Tango::DEV_VOID,
			"Startup Level.",
			"",
			Tango::OPERATOR);
	command_list.push_back(pDevStopAllCmd);

	//	Command DevGetRunningServers
	DevGetRunningServersClass	*pDevGetRunningServersCmd =
		new DevGetRunningServersClass("DevGetRunningServers",
			Tango::DEV_BOOLEAN, Tango::DEVVAR_STRINGARRAY,
			"True for all servers. False for controlled servers only.",
			"List of the processes which are running.",
			Tango::OPERATOR);
	command_list.push_back(pDevGetRunningServersCmd);

	//	Command DevGetStopServers
	DevGetStopServersClass	*pDevGetStopServersCmd =
		new DevGetStopServersClass("DevGetStopServers",
			Tango::DEV_BOOLEAN, Tango::DEVVAR_STRINGARRAY,
			"True for all servers. False for controlled servers only.",
			"List of the processes which are not running.",
			Tango::OPERATOR);
	command_list.push_back(pDevGetStopServersCmd);

	//	Command DevReadLog
	DevReadLogClass	*pDevReadLogCmd =
		new DevReadLogClass("DevReadLog",
			Tango::DEV_STRING, Tango::CONST_DEV_STRING,
			"server name and domain (e.g. Starter/corvus)\nIf argin ==``Starter``     -> return Starter logg file content.\nIf argin ==``Statistics``  -> return Starter statistics file content.",
			"String found in log file.",
			Tango::OPERATOR);
	command_list.push_back(pDevReadLogCmd);

	//	Command HardKillServer
	HardKillServerClass	*pHardKillServerCmd =
		new HardKillServerClass("HardKillServer",
			Tango::DEV_STRING, Tango::DEV_VOID,
			"Server name",
			"",
			Tango::OPERATOR);
	command_list.push_back(pHardKillServerCmd);

	//	Command ResetStatistics
	ResetStatisticsClass	*pResetStatisticsCmd =
		new ResetStatisticsClass("ResetStatistics",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::EXPERT);
	command_list.push_back(pResetStatisticsCmd);

	//	Command UpdateServersInfo
	UpdateServersInfoClass	*pUpdateServersInfoCmd =
		new UpdateServersInfoClass("UpdateServersInfo",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pUpdateServersInfoCmd);

	/*----- PROTECTED REGION ID(StarterClass::command_factory_after) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	StarterClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		StarterClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void StarterClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(StarterClass::create_static_att_list) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	StarterClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		StarterClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void StarterClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		Starter *dev = static_cast<Starter *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(StarterClass::erase_dynamic_attributes) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	StarterClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : StarterClass::get_attr_object_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *StarterClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(StarterClass::Additional Methods) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	StarterClass::Additional Methods
} //	namespace
