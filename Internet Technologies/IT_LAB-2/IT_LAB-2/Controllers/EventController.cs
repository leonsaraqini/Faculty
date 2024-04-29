using IT_LAB_2.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace IT_LAB_2.Controllers
{
    public class EventController : Controller
    {
        private static List<Event> events = new List<Event>()
        {
            new Event() { Id = 1, Name = "School Reunion", Location = "Skopje"},
            new Event() { Id = 2, Name = "Book Revision", Location = "Kumanovo"},
            new Event() { Id = 3, Name = "DJ Party", Location = "Veles"}
        };

        // GET: Event
        public ActionResult Index()
        {
            return View(events);
        }

        public ActionResult CreateNewEvent()
        {
            Event eventi = new Event();
            return View(eventi);
        }

        [HttpPost]
        public ActionResult CreateNewEvent(Event model)
        {
            if (ModelState.IsValid)
            {
                model.Id = events.Count() + 1;
                events.Add(model);

                return RedirectToAction("Index", "Event");
            }
            else
            {
                return View(model);
            }
        }

        public ActionResult EditEvent(int id)
        {
            Event eventi = events.Find(x => x.Id == id);

            return View(eventi);
        }

        [HttpPost]
        public ActionResult EditEvent(Event model)
        {
            if (ModelState.IsValid)
            {
                Event eventi = events.Find(x => x.Id == model.Id);
                
                eventi.Name = model.Name;
                eventi.Location = model.Location;
                
                return RedirectToAction("Index", "Event");
            }
            else
            {
                return View(model);
            }
                   
        }

        public ActionResult DeleteEvent(int id)
        {
            Event eventi = events.Find(x => x.Id == id);

            events.Remove(eventi);

            return RedirectToAction("Index", "Event");
        }
    }
}